/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 07:56:42 by plang             #+#    #+#             */
/*   Updated: 2024/06/21 10:07:06 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// size_t	get_time_ms(void)
// {
// 	struct timeval	time;

// 	if (gettimeofday(&time, NULL) == -1)
// 		write(2, "Error, gettimeofday()\n", 22);
// 	return (time.tv_sec * 1000 + time.tv_usec / 1000);
// }

// void	ft_usleep(size_t time_ms)
// {
// 	size_t	start;

// 	start = get_time_ms();
// 	while ((get_time_ms() - start) < time_ms)
// 		usleep(500);
// }

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

