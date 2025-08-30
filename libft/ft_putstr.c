/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:12:07 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/08/23 15:34:56 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s, int *count_char)
{
	size_t	i;

	if (!s)
	{
		ft_putstr("(null)", count_char);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], count_char);
		i++;
	}
}
