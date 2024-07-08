/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:50:55 by plang             #+#    #+#             */
/*   Updated: 2024/07/08 11:51:05 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

int	digit_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	input_check(int argc, char **input)
{
	if (argc == 5 || argc == 6)
	{
		// if ((200 < (ft_atoi(input[1]))))
		// 	return (write(2, "MAX 200 seats at the table\n", 27));
		if ((0 > (ft_atoi(input[1]))) || digit_checker(input[1]))

			return (input_error("Number of philos not valid input\n"));
		if ((0 > (ft_atoi(input[2]))) || digit_checker(input[2]))
			return (input_error("Time to die not valid input\n"));
		if ((0 > (ft_atoi(input[3]))) || digit_checker(input[3]))
			return (input_error("Time to eat not valid input\n"));
		if ((0 > (ft_atoi(input[4]))) || digit_checker(input[4]))
			return (input_error("Time to sleep not valid input\n"));
	}
	if (argc == 6)
	{
		if ((0 > (ft_atoi(input[5]))) || digit_checker(input[5]))
			return (input_error("Meals to eat not valid input\n"));
	}
	return (0);
}
