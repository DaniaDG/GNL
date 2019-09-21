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
	size_t				len = 0;
	char				*tmp;
	char				buf[BUFF_SIZE + 1];
	static t_struct		*list;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	if (!list)
	{
		list = (t_struct*)malloc(sizeof(t_struct));
		list->str = NULL;
		list->fd = fd;
	}
	while (list->str)
	{
		if (ft_strchr(list->str, '\n') == NULL)
			len = ft_strlen(list->str);
		else
			len = ft_strchr(list->str, '\n') - list->str;
		*line = (char*)realloc(&line, ft_strlen(line) + len + 1);
		*line = ft_strncat(&line, list->str, len);
		tmp = ft_strdup(&list->str[len + 1]);
		free(list->str);
		list->str = ft_strdup(tmp);
		free(tmp);
	}

	while ((ret = read(fd, buf, BUFF_SIZE)) && ())
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n') == NULL)
			len = ft_strlen(buf);
		else
			len = ft_strchr(buf, '\n') - buf;
		*line = (char*)realloc(&line, ft_strlen(line) + len + 1);
		*line = ft_strncat(&line, buf, len);
		tmp = ft_strdup(&buf[len + 1]);
		free(list->str);
		list->str = ft_strdup(tmp);
		free(tmp);
		}
	}
	return (1);	
}
