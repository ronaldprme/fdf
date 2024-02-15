/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:44:02 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:44:02 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <ctype.h>
*	DESCRIPTION
*	The isdigit() function tests for a decimal digit character.
*	PARAMETERS
*	#1. The character to test.
*	RETURN VALUES
*	The isdigit() function returns zero if the character tests false and 
*	returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
