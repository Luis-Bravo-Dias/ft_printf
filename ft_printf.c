/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:02:29 by lleiria-          #+#    #+#             */
/*   Updated: 2022/01/25 13:54:11 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

static int	convert(int count, const char *input, va_list args, int print)
{
	
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int	count;
	int	print;

	count = 0;
	va_start(args, input);
	if (!input)
		return (0);
	while (*input)
	{
		if (input[count] == '%')
		{
			print = convert(count, *input, args, print)
			count++;
		}
		else
		{
			ft_putchar_fd(*input, 1);
			print++;
		}
		count++;
	}

	va_end(args);
	return (print);
}
