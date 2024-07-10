/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:52:08 by plang             #+#    #+#             */
/*   Updated: 2024/07/10 16:11:40 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_distribution(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	philo_actions(philo, "has taken a fork\n");
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_unlock(&philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	philo_actions(philo, "has taken a fork\n");
}

void	eat(t_philo *philo)
{
	fork_distribution(philo);
	if (philo->data->philo_count == 1)
		return ;
	pthread_mutex_lock(&philo->eating);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->eating);
	philo_actions(philo, "is eating\n");
	ft_usleep(philo->data->time_to_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	sleep_n_think(t_philo *philo)
{
	philo_actions(philo, "is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
	philo_actions(philo, "is thinking\n");
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		philo_actions(philo, "is thinking\n");
		ft_usleep(philo->data->time_to_eat - 10);
	}
	if (philo->id == philo->data->philo_count && \
		philo->data->philo_count % 2 != 0)
		philo_actions(philo, "is thinking\n");
	while (murder_or_full(philo) == 0)
	{
		eat(philo);
		if (philo->data->philo_count == 1)
			return (NULL);
		sleep_n_think(philo);
	}
	return (NULL);
}
