/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:09:27 by aelousse          #+#    #+#             */
/*   Updated: 2022/01/05 19:09:31 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_exit(t_params *par)
{
	if (rand() / 2 == 0)
			par->img = mlx_xpm_file_to_image(par->mlx, "imgs/exit2.xpm", \
					&par->s, &par->s);
	else
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/exit.xpm", \
				&par->s, &par->s);
		par->x_exit = par->x;
		par->y_exit = par->y;
}

void	animation(t_params *par)
{
	if (par->view < 10)
		par->view++;
	else
		par->view = 0;
	if (par->view == 0)
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/E1.xpm", &par->s, \
		&par->s);
	else if (par->view == 3)
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/E2.xpm", &par->s, \
		&par->s);
	else if (par->view == 6)
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/E3.xpm", &par->s, \
		&par->s);
	else if (par->view == 9)
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/E4.xpm", &par->s, \
		&par->s);
}

void	animate(t_params *par)
{
	animation(par);
}

int	anime(t_params *par)
{
	int	x;
	int	y;

	x = 0;
	par->x = 0;
	par->y = 0;
	while (x < par->lines)
	{
		y = 0;
		while (y < par->columns)
		{
			if (par->map[par->x][par->y] == 'Y')
				display_img(par);
			y++;
			par->y++;
		}
		par->y = 0;
		par->x++;
		x++;
	}
	par->x = 0;
	par->y = 0;
	return (0);
}
