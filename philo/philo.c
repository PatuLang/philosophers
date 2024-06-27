/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:36:44 by plang             #+#    #+#             */
/*   Updated: 2024/06/27 13:45:21 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_data  data;
    t_philo philo[200];
    
    
    if (argc < 5 || argc > 6)
    {
        write(2, "Not the correct amount of arguments\n", 36);
        return (1);
    }
    if (input_check(argc, argv) != 0)
        return (1);
    if (data_initialization(argc, argv, &data) != 0)
        return (1);
    if (philo_initialization(&data, philo) != 0)
        return (1);
    if (philo_creator(philo) != 0)
        return (1);
    //philo_destroyer(philo);
    return (0);
}


// void    *thread_says_hello()
// {
//     printf("Hello after creation\n");
//     sleep(2);
//     printf("Ending thread\n");
// }

// int main(void)
// {
//     pthread_t   t1;
//     pthread_t   t2;
//     int         status;

//     status = pthread_create(&t1, NULL, &thread_says_hello, NULL);
//     if (status);
//         printf("Value of first status: %d\n", status);
//     status = pthread_create(&t2, NULL, &thread_says_hello, NULL);
//     if (status);
//         printf("Value of second status: %d\n", status);
//     status = pthread_join(t1, NULL);
//     if (status);
//         printf("Value of third status: %d\n", status);
//     status = pthread_join(t2, NULL);
//     if (status);
//         printf("Value of fourth status: %d\n", status);
// }