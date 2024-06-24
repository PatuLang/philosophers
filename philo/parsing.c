/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:50:55 by plang             #+#    #+#             */
/*   Updated: 2024/06/24 10:57:21 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int input_check(char **arguments)
{
    int i;
    int j;
    int check_nbr;

    i = 1;
    j = 0;
    if (200 < (check_nbr = ft_atoi(arguments[1])))
    {
        write(2, "MAX 200 seats at the table\n", 27);
        return (1);
    }
    while(arguments[i])
    {
        check_nbr = ft_atoi(arguments[i]);
        if (check_nbr <= 0)
        {
            write(2, "Only digits and positive values!\n", 33);
            return (1);
        }
        while (arguments[i][j] != '\0')
        {
            if (!ft_isdigit(arguments[i][j]))
            {
                write(2, "Only digits and positive values!\n", 33);
                return (1);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}


// needs improvement, to catch individual errors!
