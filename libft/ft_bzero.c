/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:43:05 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:43:07 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	The bzero() function writes n zeroed bytes to the string s.  
*   If n is zero, bzero() does nothing.
*	PARAMETERS
*	#1. The pointer from which to begin erasing data.
*	#2. The number of bytes to erase.
*	RETURN VALUES
*	- 
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
