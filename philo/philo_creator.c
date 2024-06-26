/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:08:00 by plang             #+#    #+#             */
/*   Updated: 2024/06/26 17:27:27 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philo_routine()
{
    printf("hello from philo_routine\n");
    return (NULL);
    // eat
    // sleep
    // think
}
void    *monitor_routine()
{
    printf("hello from monitor_routine\n");
    return (NULL);
    // check murder
}

int philo_creator(t_philo *philo)
{
    pthread_t   monitor;
    int         i;

    i = 0;
    if (pthread_create(&monitor, NULL, &monitor_routine, &philo->data) != 0)
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
