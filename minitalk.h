/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assokenay <assokenay@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:30:39 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/16 21:33:22 by assokenay        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include   <unistd.h>
# include   <signal.h>
# include   <stdlib.h>
# include	<sys/types.h>

# include	<stdio.h>

# define USLEEP_TIME 20

size_t			ft_strlen_ptr(const char *str);
size_t			ft_strlen(const char *s);
int				ft_num_len(unsigned int nbr);
char			*ft_uitoa(unsigned int n);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *str);
char			*ft_strjoin_free(char **s1, char *s2);
int				ft_atoi(const char	*str);
void			ft_convert_and_send(unsigned int nbr, char 	*base,
					pid_t pid_server);
unsigned int	ft_iterative_power(unsigned int nb, int power);
void			ft_send_pid(pid_t pid_server);
void			ft_signal_received(int sig);

#endif