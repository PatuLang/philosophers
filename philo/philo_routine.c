/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:52:08 by plang             #+#    #+#             */
/*   Updated: 2024/07/05 19:18:41 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead_is(t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->eating);
	time = get_current_time() - philo->last_meal;
	if (time >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->dead_lock);
		philo->data->murder = 1;
		pthread_mutex_unlock(&philo->data->dead_lock);
		pthread_mutex_unlock(&philo->eating);
	}
	pthread_mutex_unlock(&philo->eating);
}

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
	philo_dead_is(philo);
}

void	eat(t_philo *philo)
{
	// philo_dead_is(philo);
	fork_distribution(philo);
	pthread_mutex_lock(&philo->eating);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->eating);
	philo_actions(philo, "is eating\n");
	ft_usleep(philo->data->time_to_eat);
	philo->meals_eaten++;
	if (philo->id % 2 == 0)
		pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (philo->id % 2 != 0)
		pthread_mutex_unlock(&philo->right_fork);
}

int	sleep_n_think(t_philo *philo)
{
	philo_dead_is(philo);
	philo_actions(philo, "is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
	philo_dead_is(philo);
	philo_actions(philo, "is thinking\n");
	philo_dead_is(philo);
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
	if (philo->id == philo->data->philo_count)
		philo_actions(philo, "is thinking\n");
	while (1)
	{
		eat(philo);
		sleep_n_think(philo);
	}
	return (NULL);
}

void	meal_limit_set(t_philo *philo, int *i)
{
	if (philos_are_full(&philo[*i]))
	{
		if (philo[*i].meals_eaten == philo->data->meal_count \
			&& philo[*i].all_done == 0)
		{
			philo[*i].all_done = 1;
			philo->data->full_philos++;
		}
		if (philo->data->full_philos == philo->data->philo_count)
		{
			usleep(philo->data->time_to_eat);
			printf("full philos: %d\n", philo->data->full_philos);
			int k = 0;
			while (k < philo->data->philo_count)
			{
				printf("Philo nbr: %d meals: %d\n", philo[k].id, philo[k].meals_eaten);
				k++;
			}
			exit(1);
		}
	}
	if (*i < philo->data->philo_count)
		(*i) += 1;
	if (*i == philo->data->philo_count)
		(*i) = 0;
}

void	*monitor_routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	printf("I'm monitoring %d philosophers\n", philo->data->philo_count);
	while (1)
	{
		pthread_mutex_lock(&philo->data->dead_lock);
		if (philo->data->murder == 1)
		{
			printf("Philo murder flag: %d\n", philo->data->murder);
			pthread_mutex_unlock(&philo->data->dead_lock);
			exit (1);
		}
		pthread_mutex_unlock(&philo->data->dead_lock);
		if (philo->data->meal_count != -1)
			meal_limit_set(philo, &i);
	}
	return (NULL);
}
