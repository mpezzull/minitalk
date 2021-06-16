/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assokenay <assokenay@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:36:36 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/06/16 20:55:41 by assokenay        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_num_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	nbr;
	int				i;

	nbr = n;
	i = ft_num_len(nbr);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nbr == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (nbr > 0)
	{
		str[i--] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_strjoin_free(char **s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(*s1, s2);
	free(*s1);
	*s1 = temp;
	return (*s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	tmp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!(tmp))
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		tmp[i + n] = s2[n];
		n++;
	}
	tmp[i + n] = '\0';
	return (tmp);
}

unsigned int	ft_iterative_power(unsigned int nb, int power)
{
	unsigned int	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power-- > 0)
		result = result * nb;
	return (result);
}
