/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:56:00 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/08 12:18:57 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base, unsigned int nbase)
{
	int	counter;

	counter = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		counter += ft_putchar('-');
	}
	if (nbr >= nbase)
	{
		counter += ft_putnbr_base(nbr / nbase, base, nbase);
	}
	counter += ft_putchar(base[nbr % nbase]);
	return (counter);
}
