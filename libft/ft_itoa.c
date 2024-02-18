/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:44:17 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/18 13:13:25 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Allocates (with malloc) and returns a string representing the integer 
*	received as an argument. Negative numbers must be handled.
*	PARAMETERS
*	#1. the integer to convert.
*	RETURN VALUES
*	The string representing the integer. NULL if the allocation fails.
*/

// Converter um número inteiro para string
#include "libft.h"

char	*ft_itoa(int n)
{
	static char	p[13];
	int			j;
	long		nj;

	j = 11;
	p[12] = 0;
	p[11] = '0';
	nj = n;
	if (nj < 0)
		nj = -nj;
	while (nj != 0)
	{
		p[j] = (nj % 10 + '0');
		j--;
		nj /= 10;
	}
	if (n < 0)
		p[j--] = '-';
	return (ft_strdup(&p[j + (n != 0)]));
}
