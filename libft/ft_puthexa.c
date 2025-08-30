/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:11:20 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/08/20 11:39:04 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(unsigned long long int n, int *count_char, char specifier)
{
	char	*base;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n <= 15)
		ft_putchar(base[0 + n], count_char);
	if (n > 15)
	{
		ft_puthexa(n / 16, count_char, specifier);
		ft_putchar(base[n % 16], count_char);
	}
}
