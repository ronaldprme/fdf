/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:55:02 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/18 13:07:05 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

static char	*get_projection_name(t_fdf *fdf);

void	print_nbr(t_fdf *fdf, int x, int y, int nbr)
{
	char	*str;
	void	*mlx;
	void	*win;

	mlx = fdf->mlx;
	win = fdf->win;
	str = ft_itoa(nbr);
	mlx_string_put(mlx, win, x, y, C_VAR, str);
	free (str);
}

void	print_str(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->mlx, fdf->win, x, y, C_TEXT, str);
}

void	print_menu(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	int		y;
	char	*projection;

	mlx = fdf->mlx;
	win = fdf->win;
	y = 0;
	projection = get_projection_name(fdf);
	mlx_string_put(mlx, win, 50, y += 50, C_CYAN, projection);
	mlx_string_put(mlx, win, 50, y += 35, C_TITLE, "//// CONTROLS ////");
	print_str(fdf, 50, y += 35, "Press 'ESC' to close");
	print_str(fdf, 50, y += 35, "Zoom: press '-' or '+'");
	print_str(fdf, 50, y += 20, "Move: press arrow keys");
	print_str(fdf, 50, y += 20, "Rotate X: press 'S' or 'W'");
	print_str(fdf, 50, y += 20, "Rotate Y: press 'Q' or 'E'");
	print_str(fdf, 50, y += 20, "Rotate Z: press 'A' or 'D'");
	print_str(fdf, 50, y += 20, "Scale Z: press 'Z' or 'X'");
	print_str(fdf, 50, y += 35, "To change projection view:");
	print_str(fdf, 50, y += 20, "Isometric: press 'I'");
	print_str(fdf, 50, y += 20, "Perspective: press 'P'");
	print_str(fdf, 50, y += 20, "Top View: press 'O'");
	print_str(fdf, 50, y += 35, "Colors: press 'SPACE'");
	print_str(fdf, 50, y += 35, "Reset view: press 'R'");
	print_menu2(fdf, y);
}

void	print_menu2(t_fdf *fdf, int y)
{
	int		alpha;
	int		beta;
	int		gamma;
	void	*mlx;
	void	*win;	

	mlx = fdf->mlx;
	win = fdf->win;
	alpha = (180 / M_PI * fdf->cam->alpha);
	beta = (180 / M_PI * fdf->cam->beta);
	gamma = (180 / M_PI * fdf->cam->gamma);
	mlx_string_put(mlx, win, 50, y += 35, C_TITLE, "//// DRAW INFO ////");
	print_str(fdf, 50, y += 20, "alpha [x] = " );
	print_nbr(fdf, 121, y, alpha);
	print_str(fdf, 50, y += 20, "beta  [y] = ");
	print_nbr(fdf, 121, y, beta);
	print_str(fdf, 50, y += 20, "gamma [z] = ");
	print_nbr(fdf, 121, y, gamma);
	print_str(fdf, 50, y += 20, "zoom = ");
	print_nbr(fdf, 95, y, fdf->cam->scale_factor);
	print_str(fdf, 50, y += 20, "x[   ], y[   ]");
	print_nbr(fdf, 62, y, fdf->cam->move_x);
	print_nbr(fdf, 110, y, fdf->cam->move_y);
	print_str(fdf, 50, y += 20, "--------------------------");
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
