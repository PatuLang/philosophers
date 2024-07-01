/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:08:00 by plang             #+#    #+#             */
/*   Updated: 2024/07/01 18:39:09 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_creator(t_philo *philo)
{
    pthread_t   monitor;
    int         i;

    i = 0;
    printf("Philo count in create: %d\n", philo->data->philo_count);
    if (pthread_create(&monitor, NULL, &monitor_routine, philo) != 0)
        return (write(2, "create error\n", 13), 1);
    while (i < philo->data->philo_count)
    {
        if (pthread_create(&philo[i].thread, NULL, &philo_routine, &philo[i]) != 0)
            return (write(2, "create error\n", 13), 1);
        i++;
    }
    i = 0;
    if (pthread_join(monitor, NULL) != 0)
        return (write(2, "join error\n", 11), 1);
    while (i < philo->data->philo_count)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (write(2, "join error\n", 11), 1);
        i++;
    }
    return (0);
}

// if spamming ./philo 5 400 200 200 for some time, we get a segfault and dump the core
// and when printing philo_count in philo_create we get the correct amount what we set as input
// but then it is some garbage value when we print it in the monitor_routine
// investigate this!
