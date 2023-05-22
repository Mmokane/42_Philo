/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:05:53 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/22 04:27:20 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int	main(int ac, char **av)
{
	t_utils	*utils;

	utils = malloc(sizeof(t_utils));
	if (ac == 5 || ac == 6)
	{
		if (arg_check(av))
			return (EXIT_FAILURE);
		utils_init(utils, ac, av);
		if (!philo_init(utils))
			return (0);
		if (!mutexes_init(utils))
			return (0);
		if (!threads_starter(utils))
			return (0);
		check_death(utils->philos);
	}
	else 
		printf("Error in args\n");
	return (0);
}
