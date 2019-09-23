/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:38:43 by bsausage          #+#    #+#             */
/*   Updated: 2019/09/20 12:38:44 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(char **line, char *buf)
{
	char	*tmp;

	tmp = ft_strdup(*line);
	free(*line);
	*line = ft_strjoin(tmp, buf);
	free(tmp);
	return (*line);
}

int		get_next_line(const int fd, char **line)
{
	size_t				ret;
	int					len = 0;
	static t_struct		*list;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, list->buf, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	if (!list)
	{
		list = (t_struct*)malloc(sizeof(t_struct));
		list->fd = fd;
		list->i = 0;
	}
	if (list->i != 0 && list->buf[list->i] == '\n')
		{
			list->i++;
			return (1);
		}
	if (list->i != 0)
	{
		len = ft_strchr(&list->buf[list->i], '\n') - &list->buf[list->i];
		list->buf[list->i] = '\0';
		*line = get_line(line, &list->buf[list->i + len]);
		if ((list->i = list->i + len) > BUFF_SIZE)
			list->i = 0;
	}
	while ((ret = read(fd, list->buf, BUFF_SIZE)))
	{
		if (ret == 0)
			return (0);
		list->buf[ret] = '\0';
		if (ft_strchr(list->buf, '\n') == NULL)
			*line = get_line(line, &list->buf[list->i]);
		else
		{
			len = ft_strchr(list->buf, '\n') - list->buf;
			list->buf[len] = '\0';
			*line = get_line(line, &list->buf[list->i]);
			list->i = len + 1;
			break ;
		}
	}
	return (1);	
}
