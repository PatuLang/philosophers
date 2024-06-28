/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:52:08 by plang             #+#    #+#             */
/*   Updated: 2024/06/28 18:21:55 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eat(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(&philo->right_fork);
        philo_actions(philo, "has taken a r_fork\n");
        // printf("Philo number %d picked up the right fork\n", philo->id);
    }
    pthread_mutex_lock(philo->left_fork);
    philo_actions(philo, "has taken a l_fork\n");
    // printf("Philo number %d picked up the left fork\n", philo->id);
    if (philo->id % 2 != 0)
    {
        pthread_mutex_lock(&philo->right_fork);
        philo_actions(philo, "has taken a r_fork\n");
        // printf("Philo number %d picked up the right fork\n", philo->id);
    }
    pthread_mutex_lock(&philo->eating);
    // pthread_mutex_lock(&philo->data->write_lock);
    // if (philo->last_meal + philo->data->time_to_die > get_current_time())
    // {
    //     philo->data->murder = 1;
    //     philo_actions(philo, "has died\n");
    //     // printf("Philo number %d has died\n", philo->id);
    // }
    philo->last_meal = get_current_time();
    philo_actions(philo, "is eating\n");
    // printf("Philo number %d is eating\n", philo->id);
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->eating);
    if (philo->id % 2 == 0)
        pthread_mutex_unlock(&philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    if (philo->id % 2 != 0)
        pthread_mutex_unlock(&philo->right_fork);
    // pthread_mutex_unlock(&philo->data->write_lock);
}

void    sleep_n_think(t_philo *philo)
{
    philo_actions(philo, "is sleeping\n");
    // printf("Philo number %d is sleeping\n", philo->id);
    ft_usleep(philo->data->time_to_sleep);
    philo_actions(philo, "is thinking\n");
    // printf("Philo number %d is thinking\n", philo->id);
}

void    *philo_routine(void* arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(philo->data->time_to_eat);
    while (philo->data->murder == 0)
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
    return (NULL);
    // check murder
}
