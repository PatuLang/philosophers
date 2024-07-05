/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:08:00 by plang             #+#    #+#             */
/*   Updated: 2024/07/05 19:07:37 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_creator(t_philo *philo)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	printf("Philo count in create: %d\n", philo->data->philo_count);
	if (pthread_create(&monitor, NULL, &monitor_routine, philo) != 0)
		return (write(2, "create error\n", 13));
	while (i < philo->data->philo_count)
	{
		if (pthread_create(&philo[i].thread, NULL, &philo_routine, \
			&philo[i]) != 0)
			return (write(2, "create error\n", 13));
		i++;
	}
	i = 0;
	if (pthread_join(monitor, NULL) != 0)
		return (write(2, "join error\n", 11));
	while (i < philo->data->philo_count)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (write(2, "join error\n", 11));
		i++;
	}
	return (0);
}
