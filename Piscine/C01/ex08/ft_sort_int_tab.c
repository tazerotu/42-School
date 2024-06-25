/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:48:59 by ttas              #+#    #+#             */
/*   Updated: 2024/03/18 14:25:45 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	tempsize;
	int	tempvalue;
	int	count;

	size--;
	count = 0;
	tempsize = 0;
	while (count < size)
	{
		while (tab[tempsize] != '\0')
		{
			if (tab[tempsize] > tab[(tempsize + 1)] && (tempsize < size))
			{
				tempvalue = tab[tempsize];
				tab[tempsize] = tab[(tempsize + 1)];
				tab[(tempsize + 1)] = tempvalue;
			}
			tempsize++;
		}
		count++;
		tempsize = 0;
	}
}
