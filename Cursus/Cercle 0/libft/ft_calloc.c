/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:49:23 by ttas              #+#    #+#             */
/*   Updated: 2024/05/06 10:09:47 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else
	{
		res = (void *)malloc(nmemb * size);
		if (!res)
			return (NULL);
		ft_bzero(res, (size * nmemb));
		return (res);
	}
}
