/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:19:57 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/13 16:05:15 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <pthread.h>
# include <fcntl.h>

typedef struct s_utils
{
	size_t	philos_size;
	int		philo_nb;
}	t_utils;

typedef struct s_flsf
{
	 
}	t_flsf;

void	ft_error(void);
int		main(int ac, char **av);
int		filo_creat(int ac, char **av, t_flsf **philo, t_utils *utils);

#endif