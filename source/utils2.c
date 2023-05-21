/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:44:55 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/21 06:42:36 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	real_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
// kndrbo f 1000 bch nconvertiw mn seconds l miliseconds
// kn9smo 3la 1000 bch nconveritw mn lmicroseconds l miliseconds

void	ft_usleep(int time)
{
	long long	range;

	range = real_time();
	usleep(time * 1000 * 0.9);
	while (real_time() - range < (long int)time)
		usleep(50);
}

int	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
	return (0);
}

int	arg_check(t_utils *utils, int ac)
{
	if (ac == 5)
	{
		if (utils->philos_nb > 200 || utils->philos_nb < 2
			|| utils->philos_nb > 200 || utils->dying_time < 60
			|| utils->sleeping_time < 60 || utils->zlayf == -2
			|| utils->eating_time < 60)
		{
			ft_putstr("wrong arguments, recheck them please\n", 2);
			return (0);
		}
	}
	if (ac == 6)
	{
		if (utils->philos_nb > 200 || utils->philos_nb < 2
			|| utils->dying_time < 60 || utils->eating_time < 60
			|| utils->sleeping_time < 60 || utils->zlayf < 1
			|| utils->philos_nb > 200)
		{
			ft_putstr("wrong arguments, recheck them please\n", 2);
			return (0);
		}
	}
	return (1);
}
