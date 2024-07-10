/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:43:57 by plang             #+#    #+#             */
/*   Updated: 2024/07/10 13:45:12 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}
