/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:06:58 by plang             #+#    #+#             */
/*   Updated: 2024/07/11 12:20:32 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_initialization(int argc, char **args, t_data *data)
{
	data->philo_count = ft_atoi(args[1]);
	data->time_to_die = ft_atoi(args[2]);
	data->time_to_eat = ft_atoi(args[3]);
	data->time_to_sleep = ft_atoi(args[4]);
	if (argc == 5)
		data->meal_count = -1;
	else
		data->meal_count = ft_atoi(args[5]);
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (data_mutex_error("Write lock mutex error", data, 1));
	if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
		return (data_mutex_error("Dead lock mutex error", data, 2));
	data->full_philos = 0;
	data->murder = 0;
	return (0);
}

int	philo_initialization(t_data *data, t_philo *philo)
{
	int		i;
	size_t	time;

	i = 0;
	time = get_current_time();
	while (i < data->philo_count)
	{
		philo[i].id = i + 1;
		philo[i].start_time = time;
		philo[i].last_meal = philo[i].start_time;
		philo[i].meals_eaten = 0;
		philo[i].all_done = 0;
		if (pthread_mutex_init(&philo[i].right_fork, NULL) != 0)
			return (init_mutex_error("Fork mutex error", i, philo, 1));
		if (pthread_mutex_init(&philo[i].eating, NULL) != 0)
			return (init_mutex_error("Eating mutex error", i, philo, 2));
		if (i == 0)
			philo[i].left_fork = &philo[data->philo_count - 1].right_fork;
		else
			philo[i].left_fork = &philo[i - 1].right_fork;
		philo[i].data = data;
		i++;
	}
	return (0);
}
