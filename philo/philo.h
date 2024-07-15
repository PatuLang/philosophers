/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:36:48 by plang             #+#    #+#             */
/*   Updated: 2024/07/15 16:51:45 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				philo_count;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				meal_count;
	int				full_philos;
	int				murder;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
}	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	size_t				start_time;
	size_t				last_meal;
	int					meals_eaten;
	int					all_done;
	pthread_mutex_t		right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		eating;
	t_data				*data;
}	t_philo;

/* ************************************************************************** */
/*                             philo_parsing                                  */
/* ************************************************************************** */

int		input_error(char *str);
int		input_check(int argc, char **input);
int		digit_checker(char *str);
int		checking_max_int(char **input);

/* ************************************************************************** */
/*                         philo_initialization                               */
/* ************************************************************************** */

int		data_initialization(int argc, char **args, t_data *data);
int		philo_initialization(t_data *data, t_philo *philo);

/* ************************************************************************** */
/*                             philo_creator                                  */
/* ************************************************************************** */

int		philo_creator(t_philo *philo);

/* ************************************************************************** */
/*                             philo_routine                                  */
/* ************************************************************************** */

void	fork_distribution(t_philo *philo);
void	eat(t_philo *philo);
int		sleep_n_think(t_philo *philo);
void	*philo_routine(void *arg);

/* ************************************************************************** */
/*                         philo_monitor_routine                              */
/* ************************************************************************** */

void	*monitor_routine(void *arg);
int		murder_or_full(t_philo *philo);
int		monitoring_i_died(t_philo *philo, int *j);
int		meal_limit_set(t_philo *philo, int *i);

/* ************************************************************************** */
/*                          philo_destroyer.c                                 */
/* ************************************************************************** */

int		init_mutex_error(char *str, int i, t_philo *philo, int which);
int		data_mutex_error(char *str, t_data *data, int which);
int		philo_annhilator(t_philo *philo, int i);
int		create_philo_error(char *str, int i, t_philo *philo);
int		join_philo_error(t_philo *philo, char *str);

/* ************************************************************************** */
/*                             philo_utils1                                   */
/* ************************************************************************** */

size_t	get_current_time(void);
void	ft_usleep(size_t time_ms, t_philo *philo);
void	philo_actions(t_philo *philo, char *str);
void	philo_has_died(t_philo *philo, char *str);
int		philos_are_full(t_philo *philo);

/* ************************************************************************** */
/*                             philo_utils2                                   */
/* ************************************************************************** */

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);

#endif