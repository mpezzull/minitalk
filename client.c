/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assokenay <assokenay@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:47:10 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/16 20:57:58 by assokenay        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			usleep(25);
		}
		ft_convert_and_send(str_as_num[i++], "01", pid_server);
	}
	j = 0;
	while (j++ < 8)
	{
		kill(pid_server, SIGUSR2);
		usleep(25);
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
		usleep(25);
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
		usleep(25);
	}
	else
	{
		if (*(base + nbr) == '1')
			kill(pid_server, SIGUSR1);
		else if (*(base + nbr) == '0')
			kill(pid_server, SIGUSR2);
		else
			exit(1);
		usleep(25);
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

void	ft_signal_received(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Segnale ricevuto dal server\n", 28);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	char	*str;

	signal(SIGUSR1, ft_signal_received);
	str = argv[2];
	if (argc != 3)
		return (0);
	pid_server = ft_atoi(argv[1]);
	ft_encode(str, pid_server);
	while (1)
	 	;
//	sleep(5);
}
