/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroyer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:09:01 by plang             #+#    #+#             */
/*   Updated: 2024/07/08 14:00:54 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_count)
	{
		free(&philo[i]);
		i++;
	}
}

int	init_mutex_error(char *str, int i, t_philo *philo)
{
	ft_putstr_fd(str, 2);
	if (i != 0)
	{
		while (i > 0)
		{
			pthread_mutex_destroy(&philo[i].right_fork);
			pthread_mutex_destroy(&philo[i].eating);
			i--;
		}
	}
	pthread_mutex_destroy(&philo->data->write_lock);
	pthread_mutex_destroy(&philo->data->dead_lock);
	free_philos(philo);
	return (1);
}

int	data_mutex_error(char *str, t_data *data)
{
	ft_putstr_fd(str, 2);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
	return (1);
}

int	philo_annhilator(t_philo *philo)
{
	int	i;

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
