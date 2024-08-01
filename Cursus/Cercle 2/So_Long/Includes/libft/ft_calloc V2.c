/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc V2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:37:39 by rothiery          #+#    #+#             */
/*   Updated: 2024/08/01 09:11:57 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*str;

// 	if (nmemb == 0 || size == 0)
// 	{
// 		str = malloc(0);
// 		return (str);
// 	}
// 	if (nmemb >= INT_MAX || size >= INT_MAX || nmemb * size == INT_MAX)
// 		return (NULL);
// 	str = malloc(size * nmemb);
// 	if (str == NULL)
// 		return (NULL);
// 	ft_bzero(str, nmemb * size);
// 	return (str);
// }

/*int	main(void)
{
	void	*p = ft_calloc(-5, 0);
//	char	e[] = {0, 0, 0, 0};

//	printf(("%d\n"), ft_memcmp(p, e, 4));
	printf("%s\n", (char *)p);
	free(p);
	return (0);
}*/
