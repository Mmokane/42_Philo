/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:23:16 by moskir            #+#    #+#             */
/*   Updated: 2023/05/19 01:44:53 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	threads_starter(t_utils	*utils)
{
	int	i;

	i = 0;
	utils->die = 0;
	utils->start = real_time();
	while (i < utils->philos_nb)
	{
		pthread_create(&utils->philos[i].thread, NULL,
			&my_life, &utils->philos[i]);
		pthread_detach(utils->philos[i].thread);
		i++;
		usleep(50);
	}
	return (1);
}
// create the eating fucntion; returns nothing.
// cerate thinking function , returns nothing.
// create sleeping fucntion , returns nothing.

void	*my_life(void	*arg)
{
	int			eat;
	t_philos	*philo;

	eat = 0;
	philo = (t_philos *)arg;
	if (!(philo->id % 2))
		ft_usleep(philo->utils->eating_time);
	while (1)
	{
		philo_eat(philo);
		pthread_mutex_lock(&philo->utils->mutex);
		eat++;
		pthread_mutex_unlock(&philo->utils->mutex);
		if (philo->utils->zlayf != -1)
		{
			if (eat >= philo->utils->zlayf)
			{
				pthread_mutex_lock(&philo->utils->mutex2);
				philo->done_eating = 1;
				pthread_mutex_unlock(&philo->utils->mutex2);
				break ;
			}
				// printf("zpi\n");
		}
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
