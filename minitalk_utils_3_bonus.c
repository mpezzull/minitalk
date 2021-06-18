/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:50:32 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/17 18:35:15 by mpezzull         ###   ########.fr       */
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

void	ft_signal_received(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, &"The server has received your message \n", 38);
		exit(0);
	}
}

void	ft_write_message(char	*str)
{
	write(1, &"Message from client(pid): ", 26);
	write(1, ft_uitoa(ft_pid_client(0)), ft_num_len(ft_pid_client(0)));
	write(1, &"\n", 1);
	write(1, str, ft_strlen_ptr(str));
	write(1, &"\n", 1);
}

unsigned int	ft_pid_client(int sig)
{
	static int			count_header;
	static unsigned int	pid_client;

	if (sig == -1)
	{
		count_header = 0;
		pid_client = 0;
		return (0);
	}
	if (count_header < 24)
	{
		if (sig == SIGUSR1)
			pid_client += ft_iterative_power(2, 23 - count_header++);
		if (sig == SIGUSR2)
			count_header++;
	}
	else if (count_header == 24)
		return (pid_client);
	return (0);
}
