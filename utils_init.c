/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:15:46 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/17 01:22:46 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_utils *utils)
{
	int	i;

	i = 0;
	while (i < utils->philos_nb)
	{
		utils->philos[i].id = i;
		utils->philos[i].left_fork = i;
		utils->philos[i].right_fork = (i + 1) % utils->philos_nb;
		utils->philos[i].he_ate_x_times = 0;
		utils->philos[i].eatin = 0;
		utils->philos[i].utils = utils;
		pthread_mutex_lock(&utils->philos[i].eat);
		i++;
	}
}

int	mutexes_init(t_utils *utils)
{
	int	i;

	i = 0;
	pthread_mutex_init(&utils->to_print, NULL);
	pthread_mutex_init(&utils->to_die, NULL);
	pthread_mutex_init(&utils->philos[i].mutex, NULL);
	pthread_mutex_init(&utils->philos[i].eat, NULL);
	pthread_mutex_lock(&utils->to_die);
	utils->forks = (pthread_mutex_t *)_mallloc
		(sizeof(pthread_mutex_t) * utils->philos_nb);
	if (!(utils->forks))
		return (0);
	while (i < utils->philos_nb)
	{
		pthread_mutex_init(&utils->forks[i], NULL);
		i++;
	}
	return (1);
}

int	utils_init(t_utils *utils, int ac, char **av)
{
	utils->real_time;
	utils->philos_nb = ft_atoi(av[1]);
	utils->dying_time = ft_atoi(av[2]);
	utils->eating_time = ft_atoi(av[3]);
	utils->sleeping_time = ft_atoi(av[4]);
	utils->zlayf = 0;
	if (ac == 6)
		utils->zlayf = ft_atoi(av[5]);
	utils->forks = ft_strdup("");
	utils->philos = (t_philos *)malloc((utils->philos_nb) * sizeof(t_philos));
	if (!(utils->philos))
		return (0);
	philo_init(utils);
	mutexes_init(utils);
	if (utils->philos_nb < 2 || utils->philos > 200
		|| utils->dying_time < 60 || utils->eating_time < 60
		|| utils->sleeping_time < 60 || utils->zlayf < 0)
		return (0);
	return (1);
}
