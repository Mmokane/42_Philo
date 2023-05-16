/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:19:57 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/16 01:50:30 by mmokane          ###   ########.fr       */
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

typedef struct s_philos
{
	int				id;
	int				eatin;
	int				left_fork;
	int				right_fork;
	int				he_ate_x_times;
	struct s_utils	*utils;
}	t_philos;

typedef struct s_utils
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	to_die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eat;
	t_philos		*philos;
	pthread_mutex_t	to_print;
	uint64_t		real_time;
	int				philos_nb;
	int				eating_nbs;
	uint64_t		dying_time;
	uint64_t		eating_time;
	uint64_t		sleeping_time;
}	t_utils;

int	ft_putstr(char *str, int fd);
char	*ft_strdup(char *s);
int		ft_atoi(const char *str);
int		utils_init(t_utils *utils, int ac, char **av);
int		data_destroy(t_utils *utils);


#endif