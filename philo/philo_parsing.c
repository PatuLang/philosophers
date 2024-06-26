/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:50:55 by plang             #+#    #+#             */
/*   Updated: 2024/06/25 18:53:18 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int digit_checker(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (1);
        i++;
    }
    return (0);
}

int input_check(int argc, char **input)
{
    int arg;

    arg = 0;
    if (argc == 5 || argc == 6)
    {
        if ((200 < (arg = ft_atoi(input[1]))))
            return (write(2, "MAX 200 seats at the table\n", 27), 1);
        if ((0 > (arg = ft_atoi(input[1]))) || digit_checker(input[1]))
            return (write(2, "Number of philos not valid input\n", 33), 1);
        if ((0 > (arg = ft_atoi(input[2]))) || digit_checker(input[2]))
            return (write(2, "Time to die not valid input\n", 28), 1);
        if ((0 > (arg = ft_atoi(input[3]))) || digit_checker(input[3]))
            return (write(2, "Time to eat not valid input\n", 28), 1);
        if ((0 > (arg = ft_atoi(input[4]))) || digit_checker(input[4]))
            return (write(2, "Time to sleep not valid input\n", 30), 1);
    }
    if (argc == 6)
    {
        if ((0 > (arg = ft_atoi(input[5]))) || digit_checker(input[5]))
        return (write(2, "Meals to eat not valid input\n", 29), 1);
    }
    return (0);
}
