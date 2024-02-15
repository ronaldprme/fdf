/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:47:40 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:47:42 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters 
*	specified in ’set’ removed from the beginning and the end of the string.
*	PARAMETERS
*	#1. The string to be trimmed.
*	#2. The reference set of characters to trim.
*	RETURN VALUES
*	The trimmed string. NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	j = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[j]) && j != 0)
		j--;
	if ((int)(j - i + 1) <= 0)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, i, (j - i + 1)));
}
