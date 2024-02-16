/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:31:45 by rpr               #+#    #+#             */
/*   Updated: 2023/10/28 10:43:06 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Extrair uma substring de uma string.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	ls;
	char	*substr;

	if (s == NULL)
		return (NULL);
	ls = ft_strlen(s);
	if (!s)
		return (ft_strdup(""));
	if (start >= ls)
		return (ft_strdup(""));
	ls = ft_strlen(s + start);
	if (len > ls)
		len = ls;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
