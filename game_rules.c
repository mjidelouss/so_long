/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:36:27 by aelousse          #+#    #+#             */
/*   Updated: 2022/01/01 17:36:31 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(t_params *par)
{
	if (par->map[0][par->y] != '1')
		return (1);
	if (par->map[par->lines - 1][par->y] != '1')
		return (1);
	if (par->map[par->x][0] != '1' )
		return (1);
	if (par->map[par->x][par->columns - 1] != '1')
		return (1);
	if (par->map[par->x][par->y] != '1' && par->map[par->x][par->y] != '0' \
			&& par->map[par->x][par->y] != 'E' \
			&& par->map[par->x][par->y] != 'C' \
			&& par->map[par->x][par->y] != 'P' \
			&& par->map[par->x][par->y] != 'Y')
		return (1);
	if (par->map[par->x][par->y] == 'P')
		par->player++;
	if (par->map[par->x][par->y] == 'E')
		par->exit++;
	if (par->map[par->x][par->y] == 'C')
		par->collectible++;
	return (0);
}

int	check_rectangle(t_params *par)
{
	static int	rec;

	if (rec == 0)
	{
		rec = par->y;
		return (0);
	}
	if (rec != par->y)
		return (1);
	if (par->y == par->lines)
		return (1);
	return (0);
}

int	check_map(t_params *par)
{
	par->x = 0;
	par->y = 0;
	while (par->x < par->lines)
	{
		while (par->y < par->columns)
		{
			if (check_border(par) == 1)
				return (1);
			par->y++;
		}
		par->x++;
		if (check_rectangle(par) == 1)
			return (1);
		par->y = 0;
	}
	if (par->player != 1 || par->collectible == 0 || par->exit == 0)
		return (1);
	return (0);
}
