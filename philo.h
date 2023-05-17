/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:19:57 by mmokane           #+#    #+#             */
/*   Updated: 2023/05/17 01:39:22 by mmokane          ###   ########.fr       */
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
	pthread_t		thread;
	struct s_utils	*utils;
	int				left_fork;
	int				right_fork;
	int				done_eating;
	int				eating_times;
	int				he_ate_x_times;
}	t_philos;

typedef struct s_utils
{
	int				die;
	pthread_mutex_t	eat;
	uint64_t		start;
	int				zlayf;
	pthread_mutex_t	mutex;
	pthread_mutex_t	to_die;
	pthread_mutex_t	*forks;
	t_philos		*philos;
	pthread_mutex_t	to_print;
	uint64_t		real_time;
	int				philos_nb;
	uint64_t		dying_time;
	uint64_t		eating_time;
	uint64_t		sleeping_time;
}	t_utils;

int			main(int ac, char **av);
int			threads_starter(t_utils	*utils);
void		*my_life(void	*arg);
void		philo_init(t_utils *utils);
int			mutexes_init(t_utils *utils);
int			utils_init(t_utils *utils, int ac, char **av);
int			ft_atoi(const char *str);
int			ft_putstr(char *str, int fd);
char		*ft_strdup(char *s);
int			data_destroy(t_utils *utils);
void		free_strs(char **str);
uint64_t	real_time(void);
void		ft_sleep(int time);

#endif