/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:47:10 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/18 15:05:58 by mde-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*ft_send_signals(unsigned int *str_as_num, pid_t pid_server)
{
	int	i;
	int	j;

	i = 0;
	ft_send_pid(pid_server);
	while (str_as_num[i])
	{
		if (str_as_num[i] < 128)
			j = 7;
		else
			j = 31;
		while (str_as_num[i] < (ft_iterative_power(2, j--)))
		{
			kill(pid_server, SIGUSR2);
			usleep(USLEEP_TIME);
		}
		ft_convert_and_send(str_as_num[i++], "01", pid_server);
	}
	j = 0;
	while (j++ < 8)
	{
		kill(pid_server, SIGUSR2);
		usleep(USLEEP_TIME);
	}
	return (0);
}

void	ft_send_pid(pid_t pid_server)
{
	unsigned int	pid_client;
	int				j;

	j = 23;
	pid_client = (unsigned int)getpid();
	while (pid_client < (ft_iterative_power(2, j--)))
	{
		kill(pid_server, SIGUSR2);
		usleep(USLEEP_TIME);
	}
	ft_convert_and_send(pid_client, "01", pid_server);
}

void	ft_convert_and_send(unsigned int nbr, char 	*base, pid_t pid_server)
{
	if (nbr >= 2)
	{
		ft_convert_and_send(nbr / 2, base, pid_server);
		if (*(base + (nbr % 2)) == '1')
			kill(pid_server, SIGUSR1);
		else if (*(base + (nbr % 2)) == '0')
			kill(pid_server, SIGUSR2);
		else
			exit(1);
		usleep(USLEEP_TIME);
	}
	else
	{
		if (*(base + nbr) == '1')
			kill(pid_server, SIGUSR1);
		else if (*(base + nbr) == '0')
			kill(pid_server, SIGUSR2);
		else
			exit(1);
		usleep(USLEEP_TIME);
	}
}

int	ft_encode(char *str, pid_t pid_server)
{
	unsigned int	*str_as_num;

	str_as_num = ft_str_as_num(str);
	ft_send_signals(str_as_num, pid_server);
	free(str_as_num);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	char	*str;

	signal(SIGUSR1, ft_signal_received);
	str = argv[2];
	if (argc != 3)
	{
		write(1, "Please use: ''./client 'pid_server' 'string_to_pass''\n", 54);
		return (0);
	}
	if ((ft_strlen(argv[1]) < 3) || (ft_strlen(argv[1]) > 5))
	{
		write(1, "100<= pid_server >=99998 './server' to know right pid\n", 54);
		return (0);
	}	
	pid_server = ft_atoi(argv[1]);
	if (pid_server <= 0)
	{
		write(1, "100<= pid_server >=99998 './server' to know right pid\n", 54);
		return (0);
	}	
	ft_encode(str, pid_server);
	while (1)
	 	;
}
