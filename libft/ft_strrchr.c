/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:47:29 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:47:31 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	The strchr() function locates the last occurrence of c (converted to a 
*	char) in the string pointed to by s. The terminating null character is 
*	considered to be part of the string; therefore if c is `\0', the functions 
*	locate the terminating `\0'.
*	PARAMETERS
*	#1. The string in which to check the occurence of c.
*	#2. The character to check the occurence of.
*	RETURN VALUES
*	The function strrchr() returns a pointer to the located 
*	character, or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	ch = (unsigned char)c;
	len = ft_strlen((char *)s);
	if (ch == '\0')
		return ((char *)(&s[len]));
	while (--len >= 0)
	{
		if (s[len] == ch)
			return ((char *)(&s[len]));
	}
	return (NULL);
}
