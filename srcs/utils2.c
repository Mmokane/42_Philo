/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:44:55 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/22 04:32:41 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
		usleep(90);
}

int	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
	return (0);
}

int	ft_isdigit(int digit)
{
	if (digit >= 48 && digit <= 57)
        return (1);
    return (0);
}

int	arg_check(char **av)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	
	while (av[i])
	{
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (printf("Error, some arg are not numbers\n"));
			j++;
		}
		if (ft_atoi(av[i]) <= 0)
			return (printf("Error, an arg is negative\n"));
		i++;
	}
	return (0);
}

