/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:12:56 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/08/20 11:39:16 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(unsigned long int ptr, int *count_char)
{
	if (ptr == 0)
		return (ft_putstr("(nil)", count_char));
	ft_putstr("0x", count_char);
	ft_puthexa(ptr, count_char, 'x');
}
