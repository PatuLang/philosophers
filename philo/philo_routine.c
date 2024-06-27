/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:52:08 by plang             #+#    #+#             */
/*   Updated: 2024/06/27 20:15:40 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eat(t_philo *philo)
{
    printf("Philo number %d is eating\n", philo->id);
    usleep(philo->data->time_to_eat);
}

void    sleep_n_think(t_philo *philo)
{
    printf("Philo number %d is sleeping\n", philo->id);
    usleep(philo->data->time_to_sleep);
    printf("Philo number %d is thinking\n", philo->id);
}

void    *philo_routine(void* arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        eat(philo);
        sleep_n_think(philo);
        if (philo->data->murder == 1)
            break ;
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
