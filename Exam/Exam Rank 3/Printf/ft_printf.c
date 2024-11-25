#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		putchar(str[i]);
		i++;
	}
	return i;
}

int num_len(int nbr)
{
	int i = 0;
	while(nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	i++;
	return i;
}

int putnbr(int nbr)
{
	int i = 0;
	if(nbr == -2147483648)
	{
		putstr("-2147483648");
		return 11;
	}
	if(nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		i++;
	}
	i += num_len(nbr);
	if(nbr >= 10)
	{
		putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
	return i;
}

int num_len_hexa(unsigned int nbr)
{
	int i = 0;
	while(nbr >= 16)
	{
		nbr = nbr / 16;
		i++;
	}
	i++;
	return i;
}

int puthexa(unsigned int nbr, char *base)
{
	int i = 0;
	i += num_len_hexa(nbr);
	if(nbr >= 16)
	{
		puthexa(nbr / 16, base);
		nbr = nbr % 16;
	}
	if(nbr < 16)
	{
		ft_putchar(base[nbr % 16]);
	}
	return i;
}

int parser(char c, va_list args)
{
	int i = 0;
	if(c == 's')
		i = putstr(va_arg(args, char *));
	if(c == 'd')
		i = putnbr(va_arg(args, int));
	if(c == 'x')
		i = puthexa(va_arg(args, unsigned int), "0123456789abcdef");
	return i;
}

int ft_printf(const char *format, ... )
{
	int written = 0;
	char currentchar;
	va_list args;

	va_start(args, format);
	while(*format != '\0')
	{
		currentchar = *format;
		format++;
		if(currentchar != '%')
		{
			ft_putchar(currentchar);
			written++;
		}
		else
		{
			written += parser(*format, args);
			format++;
		}
	}
	va_end(args);
	return written;	

}

int main()
{
	int i, j;
	i = ft_printf("%x", 2147483647);
	printf("\n");
	j = printf("%x", 2147483647);
	printf("\n%d\t%d\n\n", i, j);
	return 1;
}