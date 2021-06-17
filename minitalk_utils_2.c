/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:49:08 by assokenay         #+#    #+#             */
/*   Updated: 2021/06/17 16:38:42 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen_ptr(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		len;

	len = ft_strlen(src);
	copy = ((char *)malloc(sizeof(char) * (len + 1)));
	if (copy == NULL)
		return (0);
	ft_strcpy(copy, src);
	return (copy);
}

int	ft_atoi(const char	*str)
{
	size_t	result;
	int		digit;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i++] - '0';
		result = (10 * result) + digit;
	}
	if (sign % 2 == 1)
		return ((int)(-result));
	return ((int)(result));
}
