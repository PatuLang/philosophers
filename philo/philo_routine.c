/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:52:08 by plang             #+#    #+#             */
/*   Updated: 2024/06/26 19:13:15 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philo_routine(void* arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    printf("Philo number %d ready\n", philo->id);
    return (NULL);
    // eat
    // sleep
    // think
}
void    *monitor_routine(void* arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    printf("I'm monitoring %d philosophers\n", philo->data->philo_count);
    return (NULL);
    // check murder
}
