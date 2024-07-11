/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroyer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:09:01 by plang             #+#    #+#             */
/*   Updated: 2024/07/11 14:01:20 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_error(char *str, int i, t_philo *philo)
{
	int	j;

	j = i;
	philo->data->murder = 1;
	ft_putstr_fd(str, 2);
	while (j >= 0)
	{
		if (pthread_join(philo[j].thread, NULL) != 0)
		{
			ft_putstr_fd("Join error after create failed\n", 2);
			break ;
		}
		j--;
	}
	while (i >= 0)
	{
		pthread_mutex_destroy(&philo[i].right_fork);
		pthread_mutex_destroy(&philo[i].eating);
		i--;
	}
	pthread_mutex_destroy(&philo->data->write_lock);
	pthread_mutex_destroy(&philo->data->dead_lock);
	return (1);
}

int	init_mutex_error(char *str, int i, t_philo *philo, int which)
{
	if (which == 2 && i != 0)
	{
		pthread_mutex_destroy(&philo[i].right_fork);
		i -= 1;
	}
	philo->data->murder = 1;
	ft_putstr_fd(str, 2);
	while (i >= 0)
	{
		pthread_mutex_destroy(&philo[i].right_fork);
		pthread_mutex_destroy(&philo[i].eating);
		i--;
	}
	pthread_mutex_destroy(&philo->data->write_lock);
	pthread_mutex_destroy(&philo->data->dead_lock);
	return (1);
}

int	data_mutex_error(char *str, t_data *data, int which)
{
	if (which == 1)
		ft_putstr_fd(str, 2);
	else if (which == 2)
	{
		ft_putstr_fd(str, 2);
		pthread_mutex_destroy(&data->write_lock);
	}
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

int	join_philo_error(t_philo *philo, char *str)
{
	int	i;

	i = 0;
	ft_putstr_fd(str, 2);
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
