/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:16:33 by madorna-          #+#    #+#             */
/*   Updated: 2020/08/10 18:54:09 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** #1. file descriptor for reading
** #2. The value of what has been read
**
** Write a function which returns a line read from a
** file descriptor, without the newline.
**
** RETURNS
** 1 : A line has been read
** 0 : EOF has been reached
** -1 : An error happened
**
** ALLOWED
** read, malloc, free
*/

char	*freezer(char *position, char **line, int rd)
{
	unsigned int	i;
	char			*helper;

	i = 0;
	while (position[i])
	{
		if (position[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(position))
	{
		*line = ft_substr(position, 0, i);
		helper = ft_substr(position, i + 1, ft_strlen(position) + 1);
		free(position);
		position = ft_strdup(helper);
		free(helper);
	}
	else if (rd == 0)
	{
		*line = position;
		position = NULL;
	}
	return (position);
}

int		positioner(char *buff, char **position)
{
	char	*helper;

	if (*position)
	{
		helper = ft_strjoin(*position, buff);
		free(*position);
		*position = ft_strdup(helper);
		free(helper);
	}
	else
		*position = ft_strdup(buff);
	if (ft_strchr(buff, '\n'))
		return (1);
	return (0);
}

int		check_rd(int rd, char *buff)
{
	if (rd == -1)
		free(buff);
	return (rd);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char *position[256];
	int			rd;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line
		|| !(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((rd = read(fd, buff, BUFFER_SIZE)))
	{
		if (check_rd(rd, buff) == -1)
			return (-1);
		buff[rd] = '\0';
		if (positioner(buff, &position[fd]) == 1)
			break ;
	}
	free(buff);
	if (rd <= 0 && !position[fd])
	{
		*line = ft_strdup("");
		return (rd);
	}
	position[fd] = freezer(position[fd], line, rd);
	if (rd <= 0 && !position[fd])
		return (rd);
	return (1);
}
