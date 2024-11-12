/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:57:48 by ttas              #+#    #+#             */
/*   Updated: 2024/11/12 10:42:25 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	error_message(int error)
{
	ft_putstr_fd("Error : ", ERROR_FD);
	ft_putnbr_fd(error, ERROR_FD);
	ft_putstr_fd("\n", ERROR_FD);
	exit(1);
}
