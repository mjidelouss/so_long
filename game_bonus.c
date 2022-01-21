/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:42:41 by aelousse          #+#    #+#             */
/*   Updated: 2022/01/03 15:42:43 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	return (0);
}

void	count_moves(t_params *p, int x, int y)
{
	static int	moves;

	moves++;
	if (p->map[x][y] == 'E' || p->map[x][y] == '1')
		moves--;
	if (moves != 1 && moves != 0)
		free(p->ptr);
	p->ptr = ft_itoa(moves);
	if (!p->ptr)
		return ;
	p->img = mlx_xpm_file_to_image(p->mlx, "imgs/wall.xpm", &p->s, &p->s);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	p->str = mlx_string_put(p->mlx, p->win, 5, 15, 0xFFF0FF00, \
			p->ptr);
}

void	positions(t_params *par, int x, int y)
{
	if (par->map[x][y] == 'C')
	{
		if (par->collectible >= 0)
		{
			par->map[x][y] = '0';
			par->collectible -= 1;
		}
		if (par->collectible == 0)
		{
			par->img = mlx_xpm_file_to_image(par->mlx, "imgs/exit2.xpm", \
					&par->s, &par->s);
			mlx_put_image_to_window(par->mlx, par->win, par->img, \
					par->y_exit * par->s, par->x_exit * par->s);
		}
	}
}

int	check_position(t_params *par, int x, int y)
{
	count_moves(par, x, y);
	positions(par, x, y);
	if (par->map[x][y] == '1')
		return (1);
	if (par->map[x][y] == 'Y')
	{
		printf("You're dead !");
		return (2);
	}
	if (par->map[x][y] == 'E')
	{
		if (par->collectible == 0)
		{
			printf("CONGRATS YOU WON THE ONE PIECE");
			return (2);
		}
		return (1);
	}
	return (0);
}
