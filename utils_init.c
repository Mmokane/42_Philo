/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moskir <moskir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:15:46 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/19 17:32:28 by moskir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_utils *utils)
{
	int	i;

	i = 0;
	utils->philos = malloc(sizeof(t_philos) * (utils->philos_nb));
	while (i < utils->philos_nb)
	{
		utils->philos[i].id = i;
		utils->philos[i].he_ate_x_times = 0;
		utils->philos[i].done_eating = 0;
		utils->philos[i].utils = utils;
		utils->philos[i].last_meal = real_time();
		i++;
	}
	return (1);
}

int	mutexes_init(t_utils *utils)
{
	int	i;

	i = 0;
	utils->forks = malloc(sizeof(pthread_mutex_t) * utils->philos_nb);
	while (i < utils->philos_nb)
	{
		pthread_mutex_init(&utils->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&utils->to_print, NULL);
	pthread_mutex_init(&utils->mutex1, NULL);
	pthread_mutex_init(&utils->mutex2, NULL);
	pthread_mutex_init(&utils->mutex3, NULL);
	if (!(utils->forks))
		return (0);
	return (1);
}

int	utils_init(t_utils *utils, int ac, char **av)
{
	utils->philos_nb = ft_atoi(av[1]);
	utils->dying_time = ft_atoi(av[2]);
	utils->eating_time = ft_atoi(av[3]);
	utils->sleeping_time = ft_atoi(av[4]);
	if (ac == 6)
		utils->zlayf = ft_atoi(av[5]);
	else if (ac == 5)
		utils->zlayf = -1;
	utils->forks = NULL;
	
	//utils->philos = (t_philos *)malloc((utils->philos_nb) * sizeof(t_philos));
	if (!(utils->philos))
		return (0);
	philo_init(utils);
	mutexes_init(utils);
	return (1);
}
