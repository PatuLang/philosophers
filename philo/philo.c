/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:36:44 by plang             #+#    #+#             */
/*   Updated: 2024/06/24 17:07:13 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_data  data;
    t_philo philo;
    
    if (argc == 5 || argc == 6)
    {
        if (input_check(argv))
            return (1);
        if (data_initialization(argc, argv, &data) != 0)
            return (1);
        if (philo_initialization(&data, &philo))
            return (1);
        
    }
    else
    {
        write(2, "Not the correct amount of arguments\n", 36);
        return (1);
    }
    return (0);
}

// check for input argc 5 / 6.
// args check, atoi on it, if number s valid, then args check and send one string at a time ti check it
// return 0 on success and 1 on error, return (write(1, "error message, specific\n", 1), 1);
// return 1 on error on any of these checks, otherwise run the init data, init philo and then create and run program
// last thing to do is to destroy mutexes.

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
//     if (the_creator())
//          return (1);
//     the_destroyer();
//          return (0);
// }