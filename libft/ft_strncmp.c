/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:47:20 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:47:21 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
* 	The strncmp() function compares not more than n characters. Because 
*	strncmp() is designed for comparing strings rather than binary data, 
*	characters that appear after a `\0' character are not compared.
*	PARAMETERS
*	#1. The first str to compare.
*	#2. The second str to compare.
*	#3. The number of bytes to compare the two strings.
*	RETURN VALUES
*	The strncmp() function returns an integer greater than, equal to, or less 
*	than 0, according as the string s1 is greater than, equal to, or less than 
*	the string s2.  The comparison is done using unsigned characters, so that 
*	`\200' is greater than `\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 && *s2) != '\0' && n > 0)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
