/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:29:14 by aelousse          #+#    #+#             */
/*   Updated: 2021/12/27 16:27:55 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_master(int keycode, t_params *par)
{
	int	tmp;

	tmp = 0;
	if (keycode == 53)
		free_map(par);
	if (keycode == 13)
		tmp = move_up(par, par->x_pos - 1, par->y_pos);
	if (keycode == 0)
		tmp = move_left(par, par->x_pos, par->y_pos - 1);
	if (keycode == 1)
		tmp = move_down(par, par->x_pos + 1, par->y_pos);
	if (keycode == 2)
		tmp = move_right(par, par->x_pos, par->y_pos + 1);
	if (tmp == 2)
		free_map(par);
	return (0);
}

void	free_map(t_params *par)
{
	int	x;

	x = 0;
	while (x < par->lines)
	{
		free(par->map[x]);
		x++;
	}
	free(par->map);
	if (!par->ptr)
		free(par->ptr);
	exit (0);
}

int	redcross(int i, t_params *par)
{
	(void)par;
	(void)i;
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	par;

	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		{
			printf("Fix The Path Homie");
			exit(0);
		}
		par.lines = map_lines(argv[1]);
		par.columns = map_columns(argv[1]);
		par.map = map_parser(argv[1], par);
		if (check_map(&par) == 1)
		{
			printf("Error\nInvalid Map");
			free_map(&par);
		}
		read_img(par);
	}
	else
	{
		printf("Error\nInvalid Syntax");
		exit(1);
	}
	return (0);
}
