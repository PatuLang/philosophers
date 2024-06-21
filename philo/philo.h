/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:36:48 by plang             #+#    #+#             */
/*   Updated: 2024/06/21 10:12:48 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>


typedef struct  s_data
{
    int     philo_count;
    size_t  time_to_die; // convert to ms
    size_t  time_to_eat; // convert to ms
    size_t  time_to_sleep; // convert to ms
    int     meal_count; //if (argc == 6) else = -1
}   t_data;

int ft_atoi(const char *str);
int ft_isdigit(int c);
int input_check(char **arguments);
int data_initialization(int argc, char **args, t_data *data);


// left_fork;
// right_fork;

#endif