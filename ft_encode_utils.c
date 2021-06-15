/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encode_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:36:36 by mde-rosa          #+#    #+#             */
/*   Updated: 2021/06/15 15:34:37 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_num_len(unsigned int nbr)
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
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
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

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

char	*ft_strjoin_free(char **s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(*s1, s2);
	free(*s1);
	*s1 = temp;
	return (*s1);
}

size_t  ft_strlen_ptr(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[0] != '\0')
	{
		len += 1;
		str++;
	}
	return (len);
}

char		*ft_strdup(const char *src)
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