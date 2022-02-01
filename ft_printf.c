/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:02:29 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/01 15:52:04 by lleiria-         ###   ########.fr       */
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

static	int ft_putnbr_point(unsigned long int val, char *base)
{
	int	rtn;

	rtn = 0;
	if (val >= 16)
		rtn += ft_putnbr_point(val / 16, base);
	ft_putchar_fd(base[val % 16], 1);
	rtn += 1;
	return (rtn);
}

unsigned long int	ft_putpoint(void *p)
{
	unsigned long long int val;
	
	val = (unsigned long long int)p;
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_point(val, "0123456789abcdef") + 2);
}

size_t	ft_strlen(const char	*str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_reverse(char *s)
{
	char tmp;
    int b;
    int e;

    b = 0;
    e = ft_strlen(s) - 1;
    while (b < e)
    {
        tmp = s[b];
        s[b] = s[e];
        s[e] = tmp;
        e--;
        b++;
    }
    return (s);
}

void ft_puthex (long int nbr, char flag)
{
	char	hexa[100];
	int		tmp;
	int		n;
	
	n = 0;
	while (nbr != 0)
	{
		tmp = 0;
		tmp = nbr % 16;
		if (tmp < 10)
		{
			hexa[n] = tmp + '0';
			n++;
		}
		else
		{
			if (flag == 'X')
			{
				hexa[n] = tmp + 55;
				n++;
			}
			else if (flag == 'x')
			{
				hexa[n] = tmp + 87;
				n++;
			}
		}
	}
	ft_reverse(hexa);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hexa, 1);
	
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
	else if (input[count + 1] == 'p')
		ft_putpoint(va_arg(args, long unsigned int *));
	else if (input[count + 1] == 'x' | input[count + 1] == 'X')
		ft_puthex(va_arg(args, long int), input[count + 1]);
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
	int x = 50;
   	int *ptr = &x;
   	printf("The address is: %p, the value is %d\n", ptr, *ptr);
	ft_printf("The address is: %p, the value is %d\n", ptr, *ptr);
	int data = 29;
    printf("%x (com x)\n", data);
	ft_printf("%x (com x)\n", data);
	printf("%X (com X)\n", data);
	ft_printf("%X (com X)\n", data);
}
