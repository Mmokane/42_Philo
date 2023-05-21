/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:05:53 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/19 22:36:09 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_utils	*utils;

	utils = malloc(sizeof(t_utils));
	utils_init(utils, ac, av);
	if (!arg_check(utils, ac))
		return (EXIT_FAILURE);
	if (!philo_init(utils))
		return (0);
	if (!mutexes_init(utils))
		return (0);
	if (!threads_starter(utils))
		return (0);
	check_death(utils->philos);
	return (0);
}
