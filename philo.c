/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:05:53 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/15 04:39:51 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_utils	*utils;

	utils = (t_utils *)malloc(sizeof(t_utils));
	if (ac != 5 && ac != 6)
	{
		ft_putstr("Wrong number of arguments", 2);
		(EXIT_FAILURE);
	}
	if (!utils_init(utils, ac, av))
	    return (data_destroy) // create a function that destroys thread	and mutexes.
}
