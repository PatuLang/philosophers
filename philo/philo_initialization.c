/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:06:58 by plang             #+#    #+#             */
/*   Updated: 2024/06/25 17:39:15 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int data_initialization(int argc, char **args, t_data *data)
{
    data->philo_count = ft_atoi(args[1]);
    data->time_to_die = ft_atoi(args[2]);
    data->time_to_eat = ft_atoi(args[3]);
    data->time_to_sleep = ft_atoi(args[4]);
    if (argc == 5)
        data->meal_count = -1;
    else
        data->meal_count = ft_atoi(args[5]);
    if (pthread_mutex_init(&data->write_lock, NULL) !=  0)
        return (write(2, "Mutex error\n", 12), 1);
    if (pthread_mutex_init(&data->dead_lock, NULL) !=  0)
        return (write(2, "Mutex error\n", 12), 1);
    data->murder = 0;
    return (0);
}

int philo_initialization(t_data *data, t_philo *philo)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        philo[i].id = i + 1;
        philo[i].start_time = get_current_time();
        philo[i].last_meal = 0;
        philo[i].meals_eaten = 0;
        if (pthread_mutex_init(&philo[i].right_fork, NULL) !=  0)
            return (write(2, "Mutex error\n", 12), 1);
        if (pthread_mutex_init(&philo[i].eating, NULL) !=  0)
            return (write(2, "Mutex error\n", 12), 1);
        if (i == 0)
            philo[i].left_fork = &philo[data->philo_count - 1].right_fork;
        else
            philo[i].left_fork = &philo[i - 1].right_fork;
        i++;
    }
    return (0);
}

// write error function that takes the error string and then returns 1!
// and destroys mutexes!
