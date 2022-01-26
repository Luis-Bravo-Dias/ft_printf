/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:02:29 by lleiria-          #+#    #+#             */
/*   Updated: 2022/01/26 16:05:11 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
//#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	if (!s)
		return ;
	c = 0;
	while (s[c] != '\0')
	{
		ft_putchar_fd(s[c], fd);
		c++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	p;

	if (n < 0)
	{
		p = (unsigned int)(-n);
		ft_putchar_fd('-', fd);
	}
	else
		p = (unsigned int)n;
	if (p >= 10)
	{
		ft_putnbr_fd(p / 10, fd);
		ft_putnbr_fd(p % 10, fd);
	}
	else
		ft_putchar_fd(p + '0', fd);
}

static int	convert(int count, const char *input, va_list args, int print)
{
	if (input[count + 1] == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	else if (input[count + 1] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (input[count + 1] == 'd' | input[count + 1] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (input[count + 1] == '%')
		ft_putchar_fd('%', 1);
	print++;
	return (print);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;
	int		print;

	count = 0;
	va_start(args, input);
	if (!input)
		return (0);
	while (input[count])
	{
		if (input[count] == '%')
		{
			print = convert(count, input, args, print);
			count++;
		}
		else
		{
			ft_putchar_fd(input[count], 1);
			print++;
		}
		count++;
	}
	va_end(args);
	return (print);
}

void	main()
{
	printf("Hello world (normal)\n");
	ft_printf("Hello World (normal)\n");
	printf("Hello %c (com c)\n", 'a');
	ft_printf("Hello %c (com c)\n", 'a');
	printf("Hello %s (com s)\n", "World");
	ft_printf("Hello %s (com s)\n", "World");
	printf("Hello World N %d (com d positivo)\n", 300);
	ft_printf("Hello World N %d (com d positivo)\n", 300);
	printf("Hello World N %d (com d negativo)\n", -42);
	ft_printf("Hello World N %d (com d negativo)\n", -42);
	printf("Hello World N %i (com i positivo)\n", 300);
	ft_printf("Hello World N %i (com i positivo)\n", 300);
	printf("Hello World N %i (com i negativo)\n", -42);
	ft_printf("Hello World N %i (com i negativo)\n", -42);
	printf("So many %% in this main\n");
	ft_printf("So many %% in this main\n");
}
