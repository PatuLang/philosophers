/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroyer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:09:01 by plang             #+#    #+#             */
/*   Updated: 2024/07/04 15:51:00 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_mutex_error(char *str, int i, t_philo *philo)
{
    // while (*str)
    // {
    //     write(2, &str, 1);
    //     str++;
    // }
    // write(2, "\n", 1);
    printf("%s\n", str);
    if (i != 0)
    {
        while (i > 0)
        {
            // if (&philo[i].right_fork)
                pthread_mutex_destroy(&philo[i].right_fork);
            // if (&philo[i].eating)
                pthread_mutex_destroy(&philo[i].eating);
            i--;
        }
    }
    // if (&philo->data->write_lock)
        pthread_mutex_destroy(&philo->data->write_lock);
    // if (&philo->data->dead_lock)
        pthread_mutex_destroy(&philo->data->dead_lock);
    return (1);
}

int data_mutex_error(char *str, t_data *data)
{
    // while (*str)
    // {
    //     write(2, &str, 1);
    //     str++;
    // }
    // write(2, "\n", 1);
    printf("%s\n", str);
    // if (&data->write_lock)
        pthread_mutex_destroy(&data->write_lock);
    // if (&data->dead_lock)
        pthread_mutex_destroy(&data->dead_lock);
    return (1);
}

int philo_annhilator(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->data->philo_count)
    {
        pthread_mutex_destroy(&philo[i].eating);
        pthread_mutex_destroy(&philo[i].right_fork);
        i++;
    }
    pthread_mutex_destroy(&philo->data->dead_lock);
    pthread_mutex_destroy(&philo->data->write_lock);
    return (1);
}
