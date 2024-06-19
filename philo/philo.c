/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:36:44 by plang             #+#    #+#             */
/*   Updated: 2024/06/19 13:22:55 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *thread_says_hello()
{
    printf("Hello after creation\n");
    sleep(2);
    printf("Ending thread\n");
}

int main(void)
{
    pthread_t   t1;
    pthread_t   t2;
    int         status;

    status = pthread_create(&t1, NULL, &thread_says_hello, NULL);
    if (status);
        printf("Value of first status: %d\n", status);
    status = pthread_create(&t2, NULL, &thread_says_hello, NULL);
    if (status);
        printf("Value of second status: %d\n", status);
    status = pthread_join(t1, NULL);
    if (status);
        printf("Value of third status: %d\n", status);
    status = pthread_join(t2, NULL);
    if (status);
        printf("Value of fourth status: %d\n", status);
    return (0);
}