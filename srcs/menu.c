/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:55:02 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/18 10:43:38 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

static char	*get_projection_name(t_fdf *fdf);

void	print_menu(t_fdf *fdf)
{
	int		y;
	char	*projection;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	projection = get_projection_name(fdf);
	mlx_string_put(mlx, win, 50, y += 50, C_CYAN, projection);
	mlx_string_put(mlx, win, 50, y += 35, C_TITLE, "//// CONTROLS ////");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Press 'ESC' to close");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Zoom: press '-' or '+'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Move: press arrow keys");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate X: press 'S' or 'W'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Y: press 'Q' or 'E'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Z: press 'A' or 'D'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Scale Z: press 'Z' or 'X'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "To change projection view:");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Isometric: press 'I'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Perspective: press 'P'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Top View: press 'O'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Colors: press 'SPACE'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Reset view: press 'R'");
	print_menu2(fdf, y);
}

void	print_menu2(t_fdf *fdf, int y)
{
	void	*mlx;
	void	*win;
	int		alpha;
	int		beta;
	int		gamma;

	mlx = fdf->mlx;
	win = fdf->win;
	alpha = (180 / M_PI * fdf->cam->alpha);
	beta = (180 / M_PI * fdf->cam->beta);
	gamma = (180 / M_PI * fdf->cam->gamma);
	mlx_string_put(mlx, win, 50, y += 35, C_TITLE, "//// DRAW INFO ////");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "alpha [x] = " );
	mlx_string_put(mlx, win, 121, y, C_VAR, ft_itoa(alpha));
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "beta  [y] = ");
	mlx_string_put(mlx, win, 121, y, C_VAR, ft_itoa(beta));
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "gamma [z] = ");
	mlx_string_put(mlx, win, 121, y, C_VAR, ft_itoa(gamma));
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "zoom = ");
	mlx_string_put(mlx, win, 95, y, C_VAR, ft_itoa(fdf->cam->scale_factor));
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "x[   ], y[   ]");
	mlx_string_put(mlx, win, 62, y, C_VAR, ft_itoa(fdf->cam->move_x));
	mlx_string_put(mlx, win, 110, y, C_VAR, ft_itoa(fdf->cam->move_y));
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "--------------------------");
}

static char	*get_projection_name(t_fdf *fdf)
{
	char	*projection;

	projection = "";
	if (fdf->cam->projection == ISOMETRIC)
		projection = "Isometric projection";
	else if (fdf->cam->projection == PERSPECTIVE)
		projection = "Perspective projection";
	else if (fdf->cam->projection == TOP)
		projection = "Top view";
	return (projection);
}
