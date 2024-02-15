/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:47:14 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:47:16 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
* 	Applies the function ’f’ to each character of the ’s’ to create a new 
*	string (with malloc) resulting from successive applications of ’f’.
*	PARAMETERS
*	#1. The string on which to iterate.
*	#2. The function to apply to each character.
*	RETURN VALUES
*	The string created from the successive applications of ’f’. 
*	Returns NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*c_s;

	if (!s || !f)
		return (NULL);
	c_s = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	i = -1;
	if (c_s == NULL)
		return (NULL);
	while (s[++i] != '\0')
		c_s[i] = (*f)(i, s[i]);
	c_s[i] = '\0';
	return (c_s);
}
