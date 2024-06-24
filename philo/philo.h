/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:36:48 by plang             #+#    #+#             */
/*   Updated: 2024/06/24 16:46:54 by plang            ###   ########.fr       */
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
    int             philo_count;
    size_t          time_to_die; // convert to ms
    size_t          time_to_eat; // convert to ms
    size_t          time_to_sleep; // convert to ms
    int             meal_count; //if (argc == 6) else = -1
    pthread_mutex_t dead_lock;
    pthread_mutex_t write_lock;
}   t_data;

typedef struct  s_philo
{
    pthread_t           thread;
    int                 id;
    size_t              start_time;
    size_t              last_meal;
    int                 meals_eaten;
    pthread_mutex_t     right_fork;
    pthread_mutex_t     *left_fork;
    pthread_mutex_t     eating;
    t_data              *data;
}   t_philo;

int ft_atoi(const char *str);
int ft_isdigit(int c);
int input_check(char **arguments);
int data_initialization(int argc, char **args, t_data *data);
int philo_initialization(t_data *data, t_philo *philo);


// left_fork;
// right_fork;

#endif