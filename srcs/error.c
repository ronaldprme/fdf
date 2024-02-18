/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:54:11 by rprocopi          #+#    #+#             */
/*   Updated: 2024/02/18 13:54:44 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(int exit_code)
{
	if (exit_code == 0)
		ft_putstr_fd("FDF closed. by!\n", 1);
	else if (exit_code == 1)
		ft_putstr_fd("❌Wrong usage. Expected './fdf <file_path>'.\n", 1);
	else if (exit_code == 2)
		ft_putstr_fd("❌Cannot read file.\n", 1);
	else if (exit_code == 3)
		ft_putstr_fd("❌Cannot initialize fdf.\n", 1);
	else if (exit_code == 4)
		ft_putstr_fd("❌Cannot parse map.\n", 1);
	else if (exit_code == 5)
		ft_putstr_fd("❌Cannot create image.\n", 1);
	else if (exit_code == 6)
		ft_putstr_fd("❌Cannot initialize camera.\n", 1);
	else if (exit_code == 7)
		ft_putstr_fd("❌Unable to render.\n", 1);
	else if (exit_code == 8)
		ft_putstr_fd("❌Unable to initialize color.\n", 1);
	exit(exit_code);
}
