/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:53:26 by ttas              #+#    #+#             */
/*   Updated: 2024/10/02 10:46:33 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p;
	int		len;

	len = 0;
	while (s[len])
		len++;
	str = malloc(len + 1);
	p = str;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (str);
}
