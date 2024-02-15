/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:47:46 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:47:48 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a substring from the string ’s’.
*	The substring begins at index ’start’ and is of maximum size ’len’.
*	PARAMETERS
*	#1. The string from which to create the substring.
*	#2. The start index of the substring in the string ’s’.
*	#3. The maximum length of the substring.
*	RETURN VALUES
*	The substring. NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen((char *)s);
	if (start > strlen)
		return (ft_strdup(""));
	if (strlen - start >= len)
		sstr = (char *)malloc((len + 1) * sizeof(char));
	else
		sstr = (char *)malloc((strlen - start + 1) * sizeof(char));
	if (sstr == NULL)
		return (NULL);
	ft_strlcpy(sstr, (s + start), (len + 1));
	return (sstr);
}
