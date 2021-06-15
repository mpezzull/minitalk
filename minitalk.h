/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:30:39 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/15 18:15:42 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include   <unistd.h>
# include   <signal.h>
# include   <stdlib.h>
# include   <stdio.h>

# define USLEEP_TIME 20

size_t	ft_strlen_ptr(char *str);
char	*ft_uitoa(int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
char	*ft_strjoin_free(char **s1, char *s2);

#endif