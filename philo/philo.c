/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:36:44 by plang             #+#    #+#             */
/*   Updated: 2024/07/08 14:36:22 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
	{
		return (input_error("Not the correct amount of arguments\n"));
	}
	if (input_check(argc, argv) != 0)
		return (1);
	if (data_initialization(argc, argv, &data) != 0)
		return (1);
	philo = malloc(data.philo_count * sizeof(t_philo));
	if (!philo)
		return (philo_annhilator(philo));
	if (philo_initialization(&data, philo) != 0)
	{
		free_philos(philo);
		return (philo_annhilator(philo));
	}
	if (philo_creator(philo) != 0)
	free_philos(philo);
	philo_annhilator(philo);
	return (0);
}
