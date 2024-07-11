/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 07:56:42 by plang             #+#    #+#             */
/*   Updated: 2024/07/11 13:42:54 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error gettimeofday()\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t time_ms, t_philo *philo)
{
	size_t	start;
	size_t	dead;

	dead = philo->last_meal + philo->data->time_to_die;
	start = get_current_time();
	while ((get_current_time() - start) < time_ms && get_current_time() < dead)
		usleep(500);
}

void	philo_actions(t_philo *philo, char *str)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->write_lock);
	time = get_current_time() - philo->start_time;
	if (philo->data->murder == 0 && \
		philo->data->full_philos < philo->data->philo_count)
		printf("%lu %d %s", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	philo_has_died(t_philo *philo, char *str)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->write_lock);
	time = get_current_time() - philo->start_time;
	printf("%lu %d %s", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write_lock);
}

int	philos_are_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	if (philo->meals_eaten == philo->data->meal_count)
	{
		pthread_mutex_unlock(&philo->eating);
		return (1);
	}
	pthread_mutex_unlock(&philo->eating);
	return (0);
}
