/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:05:53 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/19 09:30:09 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_utils	*utils;

	if (ac != 5 && ac != 6)
	{
		ft_putstr("Wrong number of arguments\n", 2);
	}
	utils = malloc(sizeof(t_utils));
	utils_init(utils, ac, av);
	if (!philo_init(utils))
		return (0);
	if (!mutexes_init(utils))
		return (0);
	if (!threads_starter(utils))
		return (0);
	check_death(utils->philos);
	data_destroy(utils);
	system("leaks philo");
	return (0);
}
