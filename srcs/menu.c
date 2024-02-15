/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <rprocopi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:55:02 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/14 16:15:48 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

static char	*get_projection_name(t_fdf *fdf);

int grau(double rad)
{
	return (rad * (180 / 3.14159));
}

void	print_menu(t_fdf *fdf)
{
	int		y;
	char	*projection;
	void	*mlx;
	void	*win;
	char	*zoon;
	char 	*width;
	char	*depth;
	char	*cx, *cy;
	char 	*alpha, *beta, *gamma;
	
	zoon = ft_itoa(fdf->cam->scale_factor);
	width = ft_itoa(fdf->map->max_x);
	depth = ft_itoa(fdf->map->max_y);
	cx = ft_itoa(fdf->cam->move_x);
	cy = ft_itoa(fdf->cam->move_y);
	alpha = ft_itoa(grau(fdf->cam->alpha));
	beta = ft_itoa(grau(fdf->cam->beta));
	gamma = ft_itoa(grau(fdf->cam->gamma));
	
	
	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	projection = get_projection_name(fdf);
	mlx_string_put(mlx, win, 50, y += 50, C_TEXT, projection);
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Press 'ESC' to close");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Zoom: press '-' or '+'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Move: press arrow keys");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate X: press 'S' or 'W'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Y: press 'Q' or 'E'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Z: press 'A' or 'D'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Scale Z: press 'Z' or 'X'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "(Z scale limited to 100%)");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "To change projection view:");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Isometric: press 'I'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Perspective: press 'P'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Top View: press 'O'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Colors: press 'SPACE'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Reset view: press 'R'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "________________________");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "width = ");
	mlx_string_put(mlx, win, 150, y, C_TEXT, width);
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "depth = ");
	mlx_string_put(mlx, win, 150, y, C_TEXT, depth);
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Zoon  = ");
	mlx_string_put(mlx, win, 150, y, C_TEXT, zoon);
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "X[   ] Y[   ]");
	mlx_string_put(mlx, win, 61, y, C_TEXT, cx);
	mlx_string_put(mlx, win, 104, y, C_TEXT, cy);
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "alpha = ");
	mlx_string_put(mlx, win, 150, y, C_TEXT, alpha);
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "beta = ");
	mlx_string_put(mlx, win, 150, y, C_TEXT, beta);
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "gmama = ");
	mlx_string_put(mlx, win, 150, y, C_TEXT, gamma);

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


