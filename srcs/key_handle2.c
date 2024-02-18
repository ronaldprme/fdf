/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:54:45 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/18 16:25:48 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_handle2(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_SPACE)
	{
		if (fdf->cam->color_pallet == FALSE)
			fdf->cam->color_pallet = TRUE;
		else 
			fdf->cam->color_pallet = FALSE;
	}
	else if (keycode == KEY_R)
		reset(fdf);
	return (0);
}
