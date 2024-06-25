/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:08:00 by plang             #+#    #+#             */
/*   Updated: 2024/06/25 20:04:53 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    philo_routine()
{
    
}
void    monitor_routine()
{
    
}

void    philo_creator(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->data->philo_count)
    {
        pthread_create();
    }
    i = 0;
    while (i < philo->data->philo_count)
    {
        pthread_join();
    }
}
