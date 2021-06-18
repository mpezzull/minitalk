/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:50:32 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/18 16:43:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	ft_check_argv(char	*str)
{
	if (!ft_str_is_numeric(str))
	{
		write(1, "pid_server must be a number\n", 28);
		exit(1);
	}
	if (ft_atoi(str) < 100 || ft_atoi(str) > 99998)
	{
		write(1, "pid must be in range [100,99998]\n", 33);
		exit(1);
	}	
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
