/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:47:10 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/15 18:15:00 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "minitalk.h"

unsigned int	*ft_str_as_num(char *str)
{
	int				len;
	int				i;
	unsigned int	*str_num;

	len = ft_strlen_ptr(str);
	i = 0;
	str_num = (unsigned int *)malloc((len + 1) * sizeof(unsigned int));
	if (!str_num)
		exit(1);
	while (i < len)
	{
		str_num[i] = str[i];
		i++;
	}
	str_num[i] = 0;
	return (str_num);
}

char	*ft_num_as_str(unsigned int *mat)
{
	int		len;
	char	**num_as_char;
	char	*char_as_str;
	int		i;

	char_as_str = ft_strdup("");
	len = 0;
	while (mat[len] != 0)
		len++;
	num_as_char = (char **)malloc((len + 1) * sizeof(char *));
	if (!num_as_char)
		exit(1);
	i = -1;
	while (++i < len)
		num_as_char[i] = ft_uitoa(mat[i]);
	while (--i >= 0)
	{
		ft_strjoin_free(&char_as_str, num_as_char[len - 1 - i]);
		free(num_as_char[len - 1 - i]);
		if (i != 0)
			ft_strjoin_free(&char_as_str, " ");
	}
	ft_strjoin_free(&char_as_str, "\0");
	free(num_as_char);
	return (char_as_str);
}

int	*ft_send_signals(char *num_as_str, pid_t pid_server)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (num_as_str[i] != '\0')
	{			
		x = num_as_str[i] - '0';
		while (x-- >= 0)
		{
			kill(pid_server, SIGUSR1);
			usleep(USLEEP_TIME);
		}
		kill(pid_server, SIGUSR2);
		usleep(USLEEP_TIME);
		i++;
	}
	kill(pid_server, SIGUSR2);
	usleep(USLEEP_TIME);
	kill(pid_server, SIGUSR2);
	usleep(USLEEP_TIME);
	return (0);
}

int	ft_encode(char *str, pid_t pid_server)
{
	unsigned int	*str_as_num;
	char			*num_as_str;

	str_as_num = ft_str_as_num(str);
	num_as_str = ft_num_as_str(str_as_num);
	ft_send_signals(num_as_str, pid_server);
	free(num_as_str);
	free(str_as_num);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	char	*str;

	str = argv[2];
	if (argc > 3)
		return (0);
	pid_server = atoi(argv[1]);
	ft_encode(str, pid_server);
}