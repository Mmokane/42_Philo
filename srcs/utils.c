/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 04:05:44 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/23 03:11:52 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i])
		return (0);
	return (res * sign);
}

int	check_death(t_philos *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < philo->utils->philos_nb)
		{
			lock(&philo);
			if (philo[i].utils->dying_time <= real_time() - philo[i].last_meal)
			{
				if (philo[i].done_eating != -1)
				{
					pthread_mutex_lock(&philo->utils->to_print);
					printf("%lld %d died\n", real_time() - philo->utils->start,
						philo->id);
					return (0);
				}
				else if (philo[i].done_eating == 1)
					philo->utils->meals++;
				check_teb(philo->utils->meals, philo->utils->zlayf);
			}
			unlock(&philo);
		}
	}
	return (1);
}

void	check_teb(int meals, int zlayf)
{
	if (meals == zlayf)
		return ;
}

void	lock(t_philos **philo)
{
	pthread_mutex_lock(&(*philo)->utils->mutex2);
	pthread_mutex_lock(&(*philo)->utils->mutex1);
}

void	unlock(t_philos **philo)
{
	pthread_mutex_unlock(&(*philo)->utils->mutex1);
	pthread_mutex_unlock(&(*philo)->utils->mutex2);
}
