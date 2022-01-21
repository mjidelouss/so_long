/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:53:05 by aelousse          #+#    #+#             */
/*   Updated: 2021/12/22 21:06:50 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_buff(char *buff, int fd)
{
	char	*store;
	int		r;

	store = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!store)
		return (NULL);
	r = 1;
	while (r && !(ft_strchr(buff, '\n')))
	{
		r = read(fd, store, BUFFER_SIZE);
		if (r == -1)
		{
			free(store);
			return (NULL);
		}
		store[r] = '\0';
		buff = ft_strjoin(buff, store);
	}
	free(store);
	return (buff);
}

char	*ft_get_line(char *buff)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	if (buff[0] == '\0')
		return (NULL);
	while (buff[len] != '\0' && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_leftovers(char *buff)
{
	char	*newbuff;
	int		len;
	int		i;

	len = 0;
	while (buff[len] != '\n' && buff[len] != '\0')
		len++;
	if (buff[len] == '\0')
	{
		free(buff);
		return (NULL);
	}
	i = 0;
	newbuff = (char *)malloc(sizeof(char) * (ft_strlen(buff) - len + 1));
	if (!newbuff)
		return (NULL);
	while (buff[len++] != '\0')
		newbuff[i++] = buff[len];
	newbuff[i] = '\0';
	free (buff);
	return (newbuff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read_buff(buff, fd);
	if (!buff)
		return (NULL);
	line = ft_get_line(buff);
	buff = ft_get_leftovers(buff);
	return (line);
}
