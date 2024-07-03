/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:52:08 by plang             #+#    #+#             */
/*   Updated: 2024/07/03 20:14:15 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    fork_distribution(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(&philo->right_fork);
        philo_actions(philo, "has taken a r_fork\n");
    }
    pthread_mutex_lock(philo->left_fork);
    philo_actions(philo, "has taken a l_fork\n");
    if (philo->id % 2 != 0)
    {
        // usleep(2000);
        pthread_mutex_lock(&philo->right_fork);
        philo_actions(philo, "has taken a r_fork\n");
    }
}

void philo_dead_is(t_philo *philo)
{
    size_t  time;

    time = get_current_time() - philo->last_meal;
    pthread_mutex_lock(&philo->eating);
    printf("philo: %d time: %zu last_meal: %zu\n",philo->id, time, philo->last_meal);
    // usleep(20000);
    if (time >= philo->data->time_to_die)
    {
        pthread_mutex_lock(&philo->data->dead_lock);
        philo->data->murder = 1;
        philo_actions(philo, "choked on the spagetti for sure!\n");
        pthread_mutex_unlock(&philo->data->dead_lock);
        pthread_mutex_unlock(&philo->eating);
    }
    pthread_mutex_unlock(&philo->eating);
}

void    eat(t_philo *philo)
{
    philo_dead_is(philo);
    fork_distribution(philo);
    pthread_mutex_lock(&philo->eating);
    // pthread_mutex_lock(&philo->data->write_lock);
    // if (get_current_time() - philo->last_meal > philo->data->time_to_die)
    // {
    //     philo->data->murder = 1;
    //     philo_actions(philo, "has died\n");
    //     // printf("Philo number %d has died\n", philo->id);
    // }
    philo->last_meal = get_current_time();
    ft_usleep(philo->data->time_to_eat);
    philo_actions(philo, "is eating\n");
    // printf("updated mealtime for philo:%i to :%zu\n", philo->id, philo->last_meal);
    pthread_mutex_unlock(&philo->eating);
    philo->meals_eaten++;
    if (philo->id % 2 == 0)
        pthread_mutex_unlock(&philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    if (philo->id % 2 != 0)
        pthread_mutex_unlock(&philo->right_fork);
}

int    sleep_n_think(t_philo *philo)
{
    philo_dead_is(philo);
    philo_actions(philo, "is sleeping\n");
    ft_usleep(philo->data->time_to_sleep);
    philo_dead_is(philo);
    philo_actions(philo, "is thinking\n");
    return (0);
}

void    *philo_routine(void* arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    // if (philo->id % 2 == 0)
    //     ft_usleep(philo->data->time_to_eat);
    while (1) // philo check murder function, while(!philo_murder_check)
    {
        eat(philo);
        sleep_n_think(philo);
    }
    return (NULL);
    // eat
    // sleep
    // think
    //mutexes
}
void    *monitor_routine(void* arg)
{
    t_philo *philo;
    // int     i;
    // int     full;

    // full = 0;
    philo = (t_philo *)arg;
    // i = 0;
    printf("I'm monitoring %d philosophers\n", philo->data->philo_count);
    while (1)
    {
        pthread_mutex_lock(&philo->data->dead_lock);
        if (philo->data->murder == 1)
        {
            printf("Philo murder flag: %d\n", philo->data->murder);
            pthread_mutex_unlock(&philo->data->dead_lock);
            exit (1);
        }
        pthread_mutex_unlock(&philo->data->dead_lock);
        // printf("Checking %d philos meals: %d\n", philo[i].id, philo[i].meals_eaten);
        // if (philos_are_full(&philo[i]))
        // {
        //     full++;
        //     if (full == philo->data->philo_count)
        //     {
        //         int k = 0;
        //         while (k < philo->data->philo_count)
        //         {
        //             printf("Philo nbr: %d meals: %d\n", philo[k].id, philo[k].meals_eaten);
        //             k++;
        //         }
        //         exit(0);
        //     }
        // }
        // if (i < philo->data->philo_count)
        //     i++;
        // if (i == philo->data->philo_count)
        //     i = 0;
    }
    return (NULL);
    // check murder
}
