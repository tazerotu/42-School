/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:57:48 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 11:01:02 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/So_Long.h"

void	error_message(int error)
{
	if (error == INVALID_INPUT)
		write(FD, "Error, Invalid Input", 20);
	if (error == INVALID_MAP_SIZE)
		write(FD, "Error, Map Size", 15);
	if (error == INVALID_MAP_EXIT)
		write(FD, "Error, Missing map exit", 23);
	if (error == INVALID_MAP_SIZE)
		write(FD, "Error, Map Size", 15);
	if (error == INVALID_MAP_SIZE)
		write(FD, "Error, Map Size", 15);
	exit(1);
}