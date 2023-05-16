/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:44:55 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/16 01:27:55 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_destroy(t_utils *utils)
{
	int	i;

	if (utils->forks)
	{
		i = 0;
        while (i < utils->philos_nb)
		{
			pthread_mutex_destroy(&utils->forks[i]);
			i++;
		}
        free(utils->forks);
	}
	if (utils->philos)
	{
		i = 0;
        while (i < utils->philos_nb)
        {
            pthread_mutex_destroy(&utils->philos[i].eat);
            pthread_mutex_destroy(&utils->philos[i].mutex);
            i++;
        }
        free(utils->philos);
	}
	pthread_mutex_destroy(&utils->to_print);
	pthread_mutex_destroy(&utils->to_die);
	return (1);
}