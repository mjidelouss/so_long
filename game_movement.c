/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:06:29 by aelousse          #+#    #+#             */
/*   Updated: 2021/12/26 17:00:17 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_params *box, int xx, int yy)
{
	int	ret;

	ret = check_position(box, xx, yy);
	if (ret != 0)
		return (ret);
	box->img = mlx_xpm_file_to_image(box->mlx, "imgs/luffy_u.xpm", &box->s, \
			&box->s);
	mlx_put_image_to_window(box->mlx, box->win, box->img, yy * box->s, \
			xx * box->s);
	box->img = mlx_xpm_file_to_image(box->mlx, "imgs/floor.xpm", &box->s, \
			&box->s);
	mlx_put_image_to_window(box->mlx, box->win, box->img, box->y_pos * box->s, \
			box->x_pos * box->s);
	box->x_pos -= 1;
	return (0);
}

int	move_down(t_params *box, int xx, int yy)
{
	int	ret;

	ret = check_position(box, xx, yy);
	if (ret != 0)
		return (ret);
	box->img = mlx_xpm_file_to_image(box->mlx, "imgs/luffy_d.xpm", &box->s, \
			&box->s);
	mlx_put_image_to_window(box->mlx, box->win, box->img, yy * box->s, \
			xx * box->s);
	box->img = mlx_xpm_file_to_image(box->mlx, "imgs/floor.xpm", &box->s, \
			&box->s);
	mlx_put_image_to_window(box->mlx, box->win, box->img, box->y_pos * box->s, \
			box->x_pos * box->s);
	box->x_pos += 1;
	return (0);
}

int	move_left(t_params *box, int xx, int yy)
{
	int	ret;

	ret = check_position(box, xx, yy);
	if (ret != 0)
		return (ret);
	box->img = mlx_xpm_file_to_image(box->mlx, "imgs/luffy_l.xpm", &box->s, \
			&box->s);
	mlx_put_image_to_window(box->mlx, box->win, box->img, yy * box->s, \
			xx * box->s);
	box->img = mlx_xpm_file_to_image(box->mlx, "imgs/floor.xpm", &box->s, \
			&box->s);
	mlx_put_image_to_window(box->mlx, box->win, box->img, box->y_pos * box->s, \
			box->x_pos * box->s);
	box->y_pos -= 1;
	return (0);
}

int	move_right(t_params *box, int xx, int yy)
{
	int	ret;

	ret = check_position(box, xx, yy);
	if (ret != 0)
		return (ret);
	box->img = mlx_xpm_file_to_image(box->mlx, "imgs/luffy_r.xpm", &box->s, \
			&box->s);
	mlx_put_image_to_window(box->mlx, box->win, box->img, yy * box->s, \
			xx * box->s);
	box->img = mlx_xpm_file_to_image(box->mlx, "imgs/floor.xpm", &box->s, \
			&box->s);
	mlx_put_image_to_window(box->mlx, box->win, box->img, box->y_pos * box->s, \
			box->x_pos * box->s);
	box->y_pos += 1;
	return (0);
}
