/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:52:08 by plang             #+#    #+#             */
/*   Updated: 2024/07/01 18:49:26 by plang            ###   ########.fr       */
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
        pthread_mutex_lock(&philo->right_fork);
        philo_actions(philo, "has taken a r_fork\n");
    }
}

void    eat(t_philo *philo)
{
    fork_distribution(philo);
    pthread_mutex_lock(&philo->eating);
    // pthread_mutex_lock(&philo->data->write_lock);
    // if (get_current_time() - philo->last_meal > philo->data->time_to_die)
    // {
    //     philo->data->murder = 1;
    //     philo_actions(philo, "has died\n");
    //     // printf("Philo number %d has died\n", philo->id);
    // }
    philo_actions(philo, "is eating\n");
    philo->last_meal = get_current_time();
    philo->meals_eaten++;
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->eating);
    if (philo->id % 2 == 0)
        pthread_mutex_unlock(&philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    if (philo->id % 2 != 0)
        pthread_mutex_unlock(&philo->right_fork);
}

void    sleep_n_think(t_philo *philo)
{
    philo_actions(philo, "is sleeping\n");
    ft_usleep(philo->data->time_to_sleep);
    philo_actions(philo, "is thinking\n");
}

int philo_dead_is(t_philo *philo)
{
    size_t  time;

    time = get_current_time();
    pthread_mutex_lock(&philo->data->dead_lock);
    if (time - philo->last_meal > philo->data->time_to_die)
    {
        philo->data->murder = 1;
        philo_actions(philo, "choked on the spagetti for sure!\n");
        pthread_mutex_unlock(&philo->data->dead_lock);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->dead_lock);
    return (0);
}

void    *philo_routine(void* arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(philo->data->time_to_eat);
    while (!philo_dead_is(philo)) // philo check murder function, while(!philo_murder_check)
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

    philo = (t_philo *)arg;
    printf("I'm monitoring %d philosophers\n", philo->data->philo_count);
    while (1)
    {
        if (philo->data->murder == 1)
        {
            printf("Philo murder flag: %d\n", philo->data->murder);
            exit (1);
        }
    }
    return (NULL);
    // check murder
}
