/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:44:31 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 15:44:33 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Adds the element ’new’ at the beginning of the list.
*	PARAMETERS
*	#1. The address of a pointer to the first link of a list.
*	#2. The address of a pointer to the element to be added to the list.
*	RETURN VALUES
*	-
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (*lst == NULL)
		*lst = new;
	else
	{
		elem = new;
		elem->next = *lst;
		*lst = elem;
	}
}
