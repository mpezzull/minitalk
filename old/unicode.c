/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:47:10 by mpezzull          #+#    #+#             */
/*   Updated: 2021/06/14 17:46:49 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(const char	*str)
{
	int len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);	
}

int	main(int argc, char **argv)
{
	char	*str;

	str = argv[1];
	write(1, str, 1);
	write(1, "\n", 1);
	printf("%u \n", str[0]);
	fflush(stdout);

 	char a[11] = "ciao®ciao" ;

    write(1, &a[0], strlen(&a[0])) ;
	write(1, "\n", 1);
	for (int i = 0; i < 11; i++)
		printf("%u \n", a[i]);
}
