/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:30:39 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/17 18:47:47 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include   <unistd.h>
# include   <signal.h>
# include   <stdlib.h>

# define USLEEP_TIME 25

int				ft_strlen_ptr(const char *str);
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
unsigned int	ft_pid_client(int sig);
unsigned int	*ft_str_as_num(char *str);
void			ft_send_and_clean(unsigned int *temp, char **str,
					int *count_bit);
void			ft_send(char **str);
void			ft_write_message(char	*str);

#endif