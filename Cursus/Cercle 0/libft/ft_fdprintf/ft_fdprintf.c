/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:01:02 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 09:21:33 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdprintf.h"

static int	ft_format(int fd, char c, va_list args)
{
	if (c == 's')
		return (ft_putstr_fd(fd, (char *)va_arg(args, char *)));
	else if (c == 'c')
		return (ft_putchar_fd(fd, va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar_fd(fd, '%'));
	else if (c == 'p')
		return (ft_putptr_fd(fd, va_arg(args, size_t *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(fd, va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr_fd(fd, va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_hexa_fd(fd, va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_hexa_fd(fd, va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_fdprintf(int fd, char *format, ...)
{
	va_list	args;
	size_t	writtencharacters;
	char	currentchar;

	va_start(args, format);
	writtencharacters = 0;
	while (*format != '\0')
	{
		currentchar = *format;
		format++;
		if (currentchar != '%')
		{
			ft_putchar_fd(fd, currentchar);
			writtencharacters++;
		}
		else
		{
			writtencharacters += ft_format(fd, *format, args);
			format++;
		}
	}
	va_end(args);
	return (writtencharacters);
}

int	main(void)
{
	int	i;

	i = 0;
	i = ft_fdprintf(1, "%s%d", "ceci est un nombre de test : ", -123456789);
	ft_fdprintf(1, "	|	Return : %d\n", i);
	i = ft_fdprintf(1, "ceci est un nombre de test : %i", -123456789);
	ft_fdprintf(1, "	|	Return : %d\n", i);
	i = ft_fdprintf(1, "ceci est un nombre de test : %u", -123456789);
	ft_fdprintf(1, "	|	Return : %d\n", i);
	i = ft_fdprintf(1, "ceci est un nombre Hexa de test : %x", -123456789);
	ft_fdprintf(1, "	|	Return : %d\n", i);
	i = ft_fdprintf(1, "ceci est un nombre Hexa de test : %X", -123456789);
	ft_fdprintf(1, "	|	Return : %d\n", i);
	i = ft_fdprintf(1, "pointeur :%p", "NULL");
	ft_fdprintf(1, "	|	Return : %d\n\n", i);
	printf("Ceci est la reference :\n");
	i = printf("%s%d", "ceci est un nombre de test : ", -123456789);
	printf("	|	Return : %d\n", i);
	i = printf("ceci est un nombre de test : %i", -123456789);
	printf("	|	Return : %d\n", i);
	i = printf("ceci est un nombre de test : %u", -123456789);
	printf("	|	Return : %d\n", i);
	i = printf("ceci est un nombre Hexa de test : %x", -123456789);
	printf("	|	Return : %d\n", i);
	i = printf("ceci est un nombre Hexa de test : %X", -123456789);
	printf("	|	Return : %d\n", i);
	i = printf("pointeur :%p", "NULL");
	printf("	|	Return : %d\n", i);
	return (0);
}
