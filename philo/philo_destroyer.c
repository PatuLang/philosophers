/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroyer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:09:01 by plang             #+#    #+#             */
/*   Updated: 2024/06/25 17:51:46 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int initialization_mutex_error(char *str, int i, t_philo *philo)
{
    write(2, "Mutex error\n", 12);
    if (i != 0)
    {
        while (i > 0)
        {
            if (&philo[i].right_fork)
                pthread_mutex_destroy(&philo[i].right_fork);
            if (&philo[i].eating)
                pthread_mutex_destroy(&philo[i].eating);
            i--;
        }
    }
    if (&philo->data->write_lock)
        pthread_mutex_destroy(&philo->data->write_lock);
    if (&philo->data->dead_lock)
        pthread_mutex_destroy(&philo->data->dead_lock);
    return (1);
}