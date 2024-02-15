/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:47:52 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:47:54 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <ctype.h>
*	DESCRIPTION
*	The tolower() function converts an upper-case letter to the corresponding 
*	lower-case letter.  The argument must be representable as an unsigned char 
*	or the value of EOF.
*	PARAMETERS
*	#1. The character to convert.
*	RETURN VALUES
*	If the argument is an upper-case letter, the tolower() function returns the 
*	corresponding lower-case letter if there is one; otherwise, the argument 
*	is returned unchanged.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
