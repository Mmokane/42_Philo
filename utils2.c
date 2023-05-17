/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:44:55 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/17 01:16:34 by mmokane          ###   ########.fr       */
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

void	free_strs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

uint64_t	real_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
// kndrbo f 1000 bch nconvertiw mn seconds l miliseconds
// kn9smo 3la 1000 bch nconveritw mn lmicroseconds l miliseconds

void	ft_sleep(int time)
{
	long long	range;

	time = real_time();
	usleep(time * 1000 * 0.9);
	while (real_time() - range < (long int)time)
		usleep(60);
}
