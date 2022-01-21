/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:18:34 by aelousse          #+#    #+#             */
/*   Updated: 2021/12/26 16:59:23 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(char *map)
{
	int		fd;
	int		nb;
	char	*line;

	nb = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit (0);
	line = get_next_line(fd);
	if (ft_strlen(line) == 0)
		printf("Error\nInvalid Map");
	while (line)
	{
		nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (nb < 3)
	{
		printf("Error\nInvalid Map");
		exit (0);
	}
	return (nb);
}

int	map_columns(char *map)
{
	int		fd;
	int		nb;
	int		ret;
	char	line[2];

	nb = -1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit (0);
	while (!ft_strchr(line, '\n'))
	{
		ret = read(fd, line, 1);
		if (ret < 0)
			return (0);
		line[ret] = '\0';
		nb++;
	}
	close(fd);
	if (nb < 3)
	{
		printf("Error\nInvalid Map");
		exit (0);
	}
	return (nb);
}

char	**map_parser(char *map, t_params par)
{
	int		x;
	int		fd;
	char	**store;

	x = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit (0);
	store = (char **)malloc((par.lines + 1) * sizeof(char *));
	if (!store)
		return (NULL);
	while (x < par.lines)
	{
		store[x] = malloc((par.columns + 1) * sizeof(char));
		read(fd, store[x], (par.columns + 1));
		x++;
	}
	close(fd);
	return (store);
}

void	display_img(t_params *par)
{
	if (par->map[par->x][par->y] == '1')
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/wall.xpm", &par->s, \
				&par->s);
	if (par->map[par->x][par->y] == '0')
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/floor.xpm", &par->s, \
				&par->s);
	if (par->map[par->x][par->y] == 'C')
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/collec.xpm", &par->s, \
				&par->s);
	if (par->map[par->x][par->y] == 'E')
	{
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/exit.xpm", \
				&par->s, &par->s);
		par->x_exit = par->x;
		par->y_exit = par->y;
	}
	if (par->map[par->x][par->y] == 'P')
	{
		par->img = mlx_xpm_file_to_image(par->mlx, "imgs/luffy_d.xpm", &par->s, \
				&par->s);
		par->x_pos = par->x;
		par->y_pos = par->y;
	}
	mlx_put_image_to_window(par->mlx, par->win, par->img, par->y * par->s, \
		par->x * par->s);
}

void	read_img(t_params par)
{
	par.x = 0;
	par.y = 0;
	par.mlx = mlx_init();
	par.img = mlx_xpm_file_to_image(par.mlx, "imgs/floor.xpm", &par.s, &par.s);
	par.win = mlx_new_window(par.mlx, par.s * par.columns, \
		par.s * par.lines, "game");
	mlx_hook(par.win, 17, 1L << 19, redcross, &par);
	mlx_hook(par.win, 2, 1L << 0, key_master, &par);
	while (par.x < par.lines)
	{
		while (par.y < par.columns)
		{
			display_img(&par);
			par.y++;
		}
		par.y = 0;
		par.x++;
	}
	mlx_loop(par.mlx);
}
