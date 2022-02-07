/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:06:37 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/07 16:59:27 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putnbr_base(unsigned int nbr, char *base, int nbase);

int	ft_putun(long int nb)
{
	unsigned int	unbr;
	int				counter;	

	unbr = 0;
	counter = 0;
	if (nb < 0)
	{
		unbr = (unsigned int)nb * -1;
		unbr = 4294967296 - unbr;
	}
	else if (nb >= 0)
		unbr = (unsigned)nb;
	counter += ft_putnbr_base(unbr, "0123456789", 10);
	return (counter);
}
