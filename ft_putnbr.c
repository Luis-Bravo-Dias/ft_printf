/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:23:51 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/08 12:19:04 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	p;
	int				counter;

	counter = 0;
	if (n < 0)
	{
		p = (unsigned int)(-n);
		counter += ft_putchar('-');
	}
	else
		p = (unsigned int)n;
	if (p >= 10)
	{
		counter += ft_putnbr(p / 10);
		counter += ft_putnbr(p % 10);
	}
	else
		counter += ft_putchar(p + '0');
	return (counter);
}
