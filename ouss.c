/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ouss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 04:37:00 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/18 05:04:58 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philos *philo)
{
	int	i;
	int	meals;

	i = 0;
	meals = 0;
	while (1)
	{
		i = 0;
		while (i < philo->utils->philos_nb)
		{
			pthread_mutex_lock(&philo->utils->mutex);
			pthread_mutex_lock(&philo->utils->mutex2);
			if (philo[i].utils->dying_time <= real_time() - philo[i].last_meal)
			{
				if (philo[i].done_eating != 1)
				{
					pthread_mutex_lock(&philo->utils->to_print);
					printf("%lld %d died\n", real_time() - philo->utils->start,
						philo->id);
					return (0);
				}
				else if (philo[i].done_eating == 1)
					meals++;
				if (meals == philo->utils->zlayf)
					return (0);
			}
			pthread_mutex_unlock(&philo->utils->mutex);
			pthread_mutex_unlock(&philo->utils->mutex2);
			i++;
		}
	}
	return (1);
}