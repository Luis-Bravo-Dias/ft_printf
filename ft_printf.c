/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:02:29 by lleiria-          #+#    #+#             */
/*   Updated: 2022/02/07 12:08:20 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <limits.h>
//#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

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

int	ft_putnbr_base(unsigned int nbr, char *base, int nbase)
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

int	ft_putun(long int nb)
{
	unsigned int	unbr;
	int				counter;	

	counter = 0;
	if (nb < 0)
	{
		unbr = (unsigned int)nb * -1;
		unbr = 4294967296 - unbr;
	}
	else if (nb >= 0)
		unbr = (unsigned)nb;
	counter += ft_putnbr_base(unbr, "0123456789", 10);
}

static int	convert(int n, const char *input, va_list args)
{
	int	c;

	c = 0;
	if (input[n + 1] == 'c')
		c += ft_putchar((char)va_arg(args, int));
	else if (input[n + 1] == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (input[n + 1] == 'd' | input[n + 1] == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (input[n + 1] == '%')
		c += ft_putchar('%');
	else if (input[n + 1] == 'p')
		c += ft_putpoint(va_arg(args, long unsigned int *));
	else if (input[n + 1] == 'x')
		c += ft_putnbr_base(va_arg(args, long int), "0123456789abcdef", 16);
	else if (input[n + 1] == 'X')
		c += ft_putnbr_base(va_arg(args, long int), "0123456789ABCDEF", 16);
	else if (input[n + 1] == 'u')
		c += ft_putun(va_arg(args, unsigned int));
	return (c);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		n;
	int		counter;

	n = 0;
	counter = 0;
	va_start(args, input);
	if (!input)
		return (0);
	while (input[n])
	{
		if (input[n] == '%')
		{
			counter += convert(n, input, args);
			n++;
		}
		else
		{
			counter += ft_putchar(input[n]);
		}
		n++;
	}
	va_end(args);
	return (counter);
}

/*int	main()
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
	printf("%u (com u negativo)\n", -10);
	ft_printf("%u (com u negativo)\n", -10);
    printf("%u (com u positivo)\n", 10);
    ft_printf("%u (com u positivo)\n", 10);
}*/

/*int main()
{
    system("clear");
    char chr = 'D';
    char chr2 = 'o';
    char chr3 = 'B';
    char num = '0';
    char num2 = '1';
    char num3 = '3';
    char num4 = '0';
    int numero_pos = 13;
    int numero_neg = -13;
    char *short_string = "42 Lisboa";
    char *long_string = "Eu sou um aluno da 42 Lisboa!";
    int text_fake;
    int text_original;
    int hex_number_pos = 1;
    int hex_number_neg = -1;
    char *addr_null = NULL;
    
    printf("\n-------- ORIGINAL --------\n");
    text_original = printf("hello World\n");
    printf("%d\n", text_original);
    text_original = printf("Escapes -> \\\\\\");
    printf("\n");
    printf("%d\n", text_original);
    //%c
    text_original = printf("Texto -> %ci%cgo\nTexto -> %cea\n", chr, chr2, chr3);
    printf("%d\n", text_original);
    text_original = printf("Char Num -> %c%c%c%c\n", num, num2, num3, num4);
    printf("%d\n", text_original);
    //%%
    text_original = printf("%% Char -> %%%%\n");
    printf("%d\n", text_original);
    //%d and %i
    text_original = printf("Numero Inteiro (+) ->  %i\n", numero_pos);
    printf("%d\n", text_original);
    text_original = printf("Numero Inteiro (-) -> %d\n", numero_neg);
    printf("%d\n", text_original);
    //%u
    text_original = printf("Numero Inteiro Unsigned (+) -> %u\n", numero_pos);
    printf("%d\n", text_original);
    text_original = printf("Numero Inteiro Unsigned (-) -> %u\n", numero_neg);
    printf("%d\n", text_original);
    //%s
    text_original = printf("Short String -> %s\n", short_string);
    printf("%d\n", text_original);
    text_original = printf("Long String  -> %s\n", long_string);
    printf("%d\n", text_original);
    //%x
    text_original = printf("Hex Number (Lower) (+) -> %x\n", hex_number_pos);
    printf("%d\n", text_original);
    text_original = printf("Hex Number (Lower) (-) -> %x\n", hex_number_neg);
    printf("%d\n", text_original);
    //%X
    text_original = printf("Hex Number (Upper) (+) -> %X\n", hex_number_pos);
    printf("%d\n", text_original);
    text_original = printf("Hex Number (Upper) (-) -> %X\n", hex_number_neg);
    printf("%d\n", text_original);
    //%p
    text_original = printf("Addres Pointer -> %p\n", ULONG_MAX);
    printf("%d\n", text_original);
    text_original = printf("Addres Pointer (Null) -> %p\n", addr_null);
    printf("%d\n", text_original);
    text_original = printf("--------------------------\n");
    
    printf("---------- FAKE ----------\n");
    text_fake = ft_printf("hello World\n");
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Escapes -> \\\\\\");
    ft_printf("\n");
    ft_printf("%d\n", text_fake);
    //%c
    text_fake = ft_printf("Texto -> %ci%cgo\nTexto -> %cea\n", chr, chr2, chr3);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Char Num -> %c%c%c%c\n", num, num2, num3, num4);
    ft_printf("%d\n", text_fake);
    //%%
    text_fake = ft_printf("%% Char -> %%%%\n");
    ft_printf("%d\n", text_fake);
    //%d and %i
    text_fake = ft_printf("Numero Inteiro (+) ->  %i\n", numero_pos);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Numero Inteiro (-) -> %d\n", numero_neg);
    ft_printf("%d\n", text_fake);
    //%u
    text_fake = ft_printf("Numero Inteiro Unsigned (+) -> %u\n", numero_pos);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Numero Inteiro Unsigned (-) -> %u\n", numero_neg);
    ft_printf("%d\n", text_fake);
    //%s
    text_fake = ft_printf("Short String -> %s\n", short_string);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Long String  -> %s\n", long_string);
    ft_printf("%d\n", text_fake);
    //%x
    text_fake = ft_printf("Hex Number (Lower) (+) -> %x\n", hex_number_pos);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Hex Number (Lower) (-) -> %x\n", hex_number_neg);
    ft_printf("%d\n", text_fake);
    //%X
    text_fake = ft_printf("Hex Number (Upper) (+) -> %X\n", hex_number_pos);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Hex Number (Upper) (-) -> %X\n", hex_number_neg);
    ft_printf("%d\n", text_fake);
    //%p
    text_fake = ft_printf("Addres Pointer -> %p\n", ULONG_MAX);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Addres Pointer (Null) -> %p\n", addr_null);
    ft_printf("%d\n", text_fake);
	printf("--------------------------\n");
}
*/