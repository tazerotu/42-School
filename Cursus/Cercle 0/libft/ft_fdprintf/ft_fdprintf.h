/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:56:29 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 09:15:59 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_fdprintf(int fd, char *format, ...);
int	ft_putchar_fd(int fd, char c);
int	ft_putstr_fd(int fd, char *s);
int	ft_putnbr_fd(int fd, int n);
int	ft_hexa_fd(int fd, unsigned int n, char *base);
int	ft_putptr_fd(int fd, size_t *ptr);
int	ft_putunbr_fd(int fd, unsigned int n);

#endif
