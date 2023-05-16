/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moskir <moskir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:23:16 by moskir            #+#    #+#             */
/*   Updated: 2023/05/16 23:26:29 by moskir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int threads_starter(t_utils *utils)
{
    int i;

    i = 0;
    utils->to_die = 0;
    utils->start =real_time();
    while (i < utils->philos_nb)
    {
        pthread_create(&utils->philos[i].thread, NULL,
            &my_life, &utils->philos[i]);
        pthread_detach(&utils->philos[i].thread);
        i++;
        usleep(60);
    }
    return (1);
}

void    *my_life(void   *arg)
{
    int         eat;
    t_philos    *philo;

    eat = 0;
    philo = (t_philos *)arg;
    if (!(hilo.id % 2));
        ft_sleep(philo->utils->eating_time);
    while (1)
    {
        eat(philo) // create the eating fucntion; returns nothing.
        pthread_mutex_lock(&philo->utils->eat);
        eat++;
        pthread_mutex)unlock(&philo->utils->eat);
        if (philo->utils->zlayf != -1)
        {
            if (eat >= philo->utils->zlayf)
            {
                pthread_mutex_lock(&philo->utils->mutex);
                philo->done_eating = 1;
                pthread_mutex_unlock(&philo->utils->mutex);
                break;
            }
        }
        sleep(philo) // create sleeping fucntion , returns nothing.
        think(philo) // cerate thinking function , returns nothing.
    }   
    return (NULL);
}

