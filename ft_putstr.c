/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:55:49 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/08 12:20:01 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	c;
	int	counter;

	counter = 0;
	if (!s)
		return (ft_putstr("(null)"));
	c = 0;
	while (s[c] != '\0')
	{
		counter += ft_putchar(s[c]);
		c++;
	}
	return (counter);
}
