/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:54:45 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/18 16:27:30 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	key_translate(int keycode, t_fdf *fdf);
static void	key_scale(int keycode, t_fdf *fdf);
static void	key_rotate(int keycode, t_fdf *fdf);
static void	key_project(int keycode, t_fdf *fdf);

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		close_all(fdf, 0);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP \
		|| keycode == KEY_DOWN)
		key_translate(keycode, fdf);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_Z \
		|| keycode == KEY_X || keycode == KEY_SUM || keycode == KEY_SUM2 || \
			keycode == KEY_RES || keycode == KEY_RES2 || keycode == KEY_SPD \
			|| keycode == KEY_MPD) 
		key_scale(keycode, fdf);
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D \
		|| keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E)
		key_rotate(keycode, fdf);
	else if (keycode == KEY_P || keycode == KEY_I || keycode == KEY_O)
		key_project(keycode, fdf);
	else
		key_handle2(keycode, fdf);
	render(fdf);
	return (0);
}

static void	key_translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_RIGHT)
		fdf->cam->move_x += 10;
	else if (keycode == KEY_LEFT)
		fdf->cam->move_x -= 10;
	else if (keycode == KEY_DOWN)
		fdf->cam->move_y += 10;
	else if (keycode == KEY_UP)
		fdf->cam->move_y -= 10;
}

static void	key_scale(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS || keycode == KEY_SPD)
		fdf->cam->scale_factor += 1;
	else if (keycode == KEY_MINUS || keycode == KEY_MPD || \
	keycode == KEY_RES2)
		fdf->cam->scale_factor -= 1;
	else if (keycode == KEY_Z && fdf->cam->scale_z > -1)
		fdf->cam->scale_z -= 0.1;
	else if (keycode == KEY_X && fdf->cam->scale_z < 1)
		fdf->cam->scale_z += 0.1;
}

static void	key_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_S)
		fdf->cam->alpha -= (5 * ANG_1);
	else if (keycode == KEY_W)
		fdf->cam->alpha += (5 * ANG_1);
	else if (keycode == KEY_A)
		fdf->cam->gamma -= (5 * ANG_1);
	else if (keycode == KEY_D)
		fdf->cam->gamma += (5 * ANG_1);
	else if (keycode == KEY_Q)
		fdf->cam->beta -= (5 * ANG_1);
	else if (keycode == KEY_E)
		fdf->cam->beta += (5 * ANG_1);
}

static void	key_project(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_P)
		fdf->cam->projection = PERSPECTIVE;
	else if (keycode == KEY_I)
		fdf->cam->projection = ISOMETRIC;
	else if (keycode == KEY_O)
		fdf->cam->projection = TOP;
}
