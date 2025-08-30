/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:43:58 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/08/27 15:27:25 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	ft_strlcpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	i = ft_strlen(s + start);
	if (i > len)
		i = len;
	sub = malloc(i + 1);
	if (!sub)
		return (NULL);
	sub[i] = 0;
	while (i--)
		sub[i] = s[start + i];
	return (sub);
}
