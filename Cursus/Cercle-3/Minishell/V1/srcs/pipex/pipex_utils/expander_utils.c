/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:11:13 by ttas              #+#    #+#             */
/*   Updated: 2025/04/25 14:07:57 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

int is_valid_var_char(char c)
{
	return (0);
}

// Function to verify the syntax of an environment variable in a string
// And return the variable if the syntax is correct
// returns NULL if incorrect syntax and skips to next character
// examples :
// $USER  -> ttas
// $9USER -> USER
// $USER9 -> NULL
// $USEr  -> NULL
// $USERt -> NULL
char *verify_syntax(char *str, t_expander *expander)
{
	return (NULL);
}
