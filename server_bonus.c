/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:38:16 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/18 16:46:22 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_send(char	**str)
{
	ft_write_message(*str);
	kill(ft_pid_client(0), SIGUSR1);
	free(*str);
	*str = NULL;
	ft_pid_client(-1);
}

void	ft_write_message(char	*str)
{
	write(1, &"Message from client(pid): ", 26);
	write(1, ft_uitoa(ft_pid_client(0)), ft_num_len(ft_pid_client(0)));
	write(1, &"\n", 1);
	write(1, str, ft_strlen_ptr(str));
	write(1, &"\n", 1);
}

void	ft_send_and_clean(unsigned int *temp, char **str, int *count_bit)
{
	if (!*temp)
		ft_send(str);
	*count_bit = 0;
	*temp = 0;
}

void	ft_sighandler(int sig)
{
	static unsigned int	temp;
	static int			count_bit;
	static char			buffer;
	static char			*str;

	if (!str)
		str = ft_strdup("");
	if (ft_pid_client(sig))
	{
		if (sig == SIGUSR1)
		{
			if (count_bit == 0 || temp >= ft_iterative_power(2, 31))
				temp += ft_iterative_power(2, 31 - count_bit);
			else
				temp += ft_iterative_power(2, 7 - count_bit);
		}
		count_bit++;
		if ((count_bit == 8 && temp < 128) || (count_bit == 32))
		{
			buffer = temp;
			ft_strjoin_free(&str, &buffer);
			ft_send_and_clean(&temp, &str, &count_bit);
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
