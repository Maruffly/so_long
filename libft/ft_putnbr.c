/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:14:08 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/08/23 15:34:44 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long int n, int *count_char, int is_unsigned)
{
	if (n == LONG_MIN)
	{
		write(1, "-9223372036854775808", 20);
		*count_char += 20;
		return ;
	}
	if (n < 0 && !is_unsigned)
	{
		ft_putchar('-', count_char);
		n = -n;
	}
	if (n >= 0 && n <= 9)
		ft_putchar('0' + n, count_char);
	else
	{
		ft_putnbr(n / 10, count_char, is_unsigned);
		ft_putchar(n % 10 + '0', count_char);
	}
}
