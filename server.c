/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assokenay <assokenay@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:38:16 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/16 23:47:12 by assokenay        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
void	ft_sighandler(int sig)
{
	static unsigned int	temp;
	static int			count;
	static unsigned int	pid_client;

	if (count == 0 && pid_client == 0)
		count = 17;
	if (sig == SIGUSR1)
	{
		pid_client += ft_iterative_power(2, count--);
	}
	if (sig == SIGUSR2)
	{
		count--;
	}
	if (count == -1)
	{
		kill(pid_client, SIGUSR1);
		pid_client = 0;
		count = 0;
	}
}
*/

void	ft_sighandler(int sig)
{
	static unsigned int	temp;
	static int			count;
	static int			count_bit;
	static unsigned int	pid_client;
	static char			buffer;
	static char			*str;

	if (!str)
		str = ft_strdup("");
	if (count < 24)
	{
		if (sig == SIGUSR1)
		{
			pid_client += ft_iterative_power(2, 23 - count++);
		}
		if (sig == SIGUSR2)
		{
			count++;
		}
	}
	else
	{
		if (sig == SIGUSR1)
		{
			if (count_bit == 0 || temp >= ft_iterative_power(2, 31))
				temp += ft_iterative_power(2, 31 - count_bit++);
			else
				temp += ft_iterative_power(2, 7 - count_bit++);
		}
		if (sig == SIGUSR2)
		{
			count_bit++;
		}
		if ((count_bit == 8 && temp < 128) || (count_bit == 32))
		{
			buffer = temp;
			ft_strjoin_free(&str, &buffer);
			if (!temp)
			{
				//write(1, &str, ft_strlen_ptr(str));
				printf("%s\n", str);
				fflush(stdout);
				kill(pid_client, SIGUSR1);
				free(str);
				str = NULL;
				count = 0;
				pid_client = 0;
			}
			count_bit = 0;
			temp = 0;
		}
	}
}

int	main(void)
{
	pid_t	pid;

	signal(SIGUSR1, ft_sighandler);
	signal(SIGUSR2, ft_sighandler);
	pid = getpid();
	write(1, (ft_uitoa(pid)), ft_num_len(pid));
	write(1, "\n", 1);
	while (1)
	 	;
}
