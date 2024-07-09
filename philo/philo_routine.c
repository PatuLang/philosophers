/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:52:08 by plang             #+#    #+#             */
/*   Updated: 2024/07/09 19:36:56 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_distribution(t_philo *philo)
{
	// if (philo->id % 2 == 0)
	// {
	pthread_mutex_lock(&philo->right_fork);
	philo_actions(philo, "has taken a r_fork\n");
	// }
	pthread_mutex_lock(philo->left_fork);
	philo_actions(philo, "has taken a l_fork\n");
	// if (philo->id % 2 != 0)
	// {
	//     pthread_mutex_lock(&philo->right_fork);
	//     philo_actions(philo, "has taken a r_fork\n");
	// }
}

void	eat(t_philo *philo)
{
	fork_distribution(philo);
	pthread_mutex_lock(&philo->eating);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->eating);
	philo_actions(philo, "is eating\n");
	ft_usleep(philo->data->time_to_eat);
	philo->meals_eaten++;
	// if (philo->id % 2 == 0)
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	// if (philo->id % 2 != 0)
		// pthread_mutex_unlock(&philo->right_fork);
}

int	sleep_n_think(t_philo *philo)
{
	philo_actions(philo, "is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
	philo_actions(philo, "is thinking\n");
	return (0);
}

int	murder_or_full(t_philo *philo)
{
	if (philo->data->meal_count != -1)
	{
		pthread_mutex_lock(&philo->eating);
		if (philo->data->full_philos == philo->data->philo_count)
		{
			pthread_mutex_unlock(&philo->eating);
			return (1);
		}
		pthread_mutex_unlock(&philo->eating);
	}
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->murder == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
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
		sleep_n_think(philo);
	}
	return (NULL);
}

int	meal_limit_set(t_philo *philo, int *i)
{
	if (philos_are_full(&philo[*i]))
	{
		pthread_mutex_lock(&philo[*i].eating);
		if (philo[*i].meals_eaten == philo->data->meal_count \
			&& philo[*i].all_done == 0)
		{
			philo[*i].all_done = 1;
			philo->data->full_philos++;
		}
		if (philo->data->full_philos == philo->data->philo_count)
		{
			pthread_mutex_unlock(&philo[*i].eating);
			return (1);
		}
		pthread_mutex_unlock(&philo[*i].eating);
	}
	if (*i < philo->data->philo_count)
		(*i) += 1;
	if (*i == philo->data->philo_count)
		(*i) = 0;
	return (0);
}

int	monitoring_i_died(t_philo *philo, int *j)
{
	size_t	time;

	pthread_mutex_lock(&philo[*j].eating);
	time = get_current_time() - philo->last_meal;
	if (time >= philo[*j].data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->dead_lock);
		philo->data->murder = 1;
		pthread_mutex_unlock(&philo->data->dead_lock);
		pthread_mutex_unlock(&philo[*j].eating);
		philo_has_died(&philo[*j], "died\n");
		return (1);
	}
	pthread_mutex_unlock(&philo[*j].eating);
	if (*j < philo->data->philo_count)
		(*j) += 1;
	if (*j == philo->data->philo_count)
		(*j) = 0;
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philo;
	int		i;
	int		j;

	philo = (t_philo *)arg;
	i = 0;
	j = 0;
	while (1)
	{
		if (monitoring_i_died(philo, &j))
			break ;
		if (philo->data->meal_count != -1)
		{
			if (meal_limit_set(philo, &i))
				break ;
		}
	}
	return (NULL);
}
