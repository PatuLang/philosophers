/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:06:58 by plang             #+#    #+#             */
/*   Updated: 2024/06/24 15:54:49 by plang            ###   ########.fr       */
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
    printf("philos: %d\n", data->philo_count);
    printf("die: %ld\n", data->time_to_die);
    printf("eat: %ld\n", data->time_to_eat);
    printf("sleep: %ld\n", data->time_to_sleep);
    printf("meals: %d\n", data->meal_count);
    return (0);
}

int philo_initialization(t_data *data, t_philo *philo)
{
    int i;

    i = 0;
    while (i > data->philo_count)
    {
        philo[i].id = i + 1;
        
        i++;
    }
}
