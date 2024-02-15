/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:46:44 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:46:46 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Applies the function f to each character of the string passed as argument, 
*	and passing its index as first argument. Each character is passed by
*	address to f to be modified if necessary.
*	PARAMETERS
*	#1. The string on which to iterate.
*	#2. The function to apply to each character.
*	RETURN VALUES
*	-
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i] != '\0')
		(*f)(i, &s[i]);
}
