/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:09:12 by aelousse          #+#    #+#             */
/*   Updated: 2021/12/27 16:28:17 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1024

typedef struct s_params{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	char	*ptr;
	int		str;
	int		x;
	int		y;
	int		lines;
	int		columns;
	int		x_pos;
	int		y_pos;
	int		x_exit;
	int		y_exit;
	int		s;
	int		player;
	int		collectible;
	int		exit;
	int		view;
}	t_params;

char	*get_next_line(int fd);
char	*ft_read_buff(char *buff, int fd);
char	*ft_get_line(char *buff);
char	*ft_get_leftovers(char *buff);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_itoa(int n);
int		redcross(int i, t_params *par);
int		key_master(int keycode, t_params *par);
void	free_map(t_params *par);
void	count_moves(t_params *p, int x, int y);
int		map_lines(char *map);
int		map_columns(char *map);
char	**map_parser(char *map, t_params par);
int		check_position(t_params *par, int x, int y);
void	positions(t_params *par, int x, int y);
void	read_img(t_params par);
void	display_img(t_params *par);
int		move_up(t_params *box, int xx, int yy);
int		move_down(t_params *box, int xx, int yy);
int		move_left(t_params *box, int xx, int yy);
int		move_right(t_params *box, int xx, int yy);
int		check_map(t_params *par);
int		check_border(t_params *par);
int		check_rectangle(t_params *par);
void	animation(t_params *par);
void	animate_exit(t_params *par);
void	animate(t_params *par);
int		anime(t_params *par);

#endif
