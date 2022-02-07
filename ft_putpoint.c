/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:06:10 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/07 16:15:48 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_putnbr_point(unsigned long int val, char *base)
{
	int	counter;

	counter = 0;
	if (val >= 16)
	{
		counter += ft_putnbr_point(val / 16, base);
	}
	counter += ft_putchar(base[val % 16]);
	return (counter);
}

int	ft_putpoint(void *p)
{
	unsigned long long int	val;
	int						counter;

	counter = 0;
	val = (unsigned long long int)p;
	counter += ft_putstr("0x");
	counter += ft_putnbr_point(val, "0123456789abcdef");
	return (counter);
}
