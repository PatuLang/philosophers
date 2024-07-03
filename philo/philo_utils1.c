/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 07:56:42 by plang             #+#    #+#             */
/*   Updated: 2024/07/03 18:52:48 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error gettimeofday()\n");// write(2, "Error, gettimeofday()\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t time_ms)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < time_ms)
		usleep(500);
}

void	philo_actions(t_philo *philo, char *str)
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

static	int	ft_conversion(const char *str, int negative, long result, long prev)
{
	while (*str >= 48 && *str <= 57)
	{
		prev = result;
		result = result * 10 + *str - '0';
		str++;
		if (result < prev || (result % 100) / 10 != prev % 10)
		{
			if (negative == 1)
				return (-1);
			return (0);
		}
	}
	return (result * negative);
}

int	ft_atoi(const char *str)
{
	int		negative;
	long	result;
	long	prev;

	negative = 1;
	result = 0;
	prev = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
	{
		negative = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	return (ft_conversion(str, negative, result, prev));
}


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

