/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:38:16 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/15 17:52:03 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"

void	ft_sighandler(int sig)
{
	static char			*str;
	static unsigned int	temp;
	static int			zeros;
	static char			buffer;

	if (!str)
		str = ft_strdup("");
	if (sig == SIGUSR1)
	{
		if (zeros == 0)
			temp++;
		if (zeros == 1)
		{
			temp *= 10;
			temp++;
		}
		zeros = 0;
	}
	if (sig == SIGUSR2)
	{
		zeros++;
		if (zeros == 1)
			temp--;
		if (zeros == 2)
		{	
			buffer = temp;
			ft_strjoin_free(&str, &buffer);
			temp = 0;
			zeros = 0;
		}
	}
	if (temp == 4294967295)
	{
		printf("%s\n", str);
		free(str);
		str = NULL;
		temp = 0;
		buffer = 0;
		zeros = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	char	*addr;
	char	value;

	signal(SIGUSR1, ft_sighandler);
	signal(SIGUSR2, ft_sighandler);
	pid = getpid();
	printf("%u\n", pid);
	while (1)
	 	;
}
