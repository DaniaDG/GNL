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





int		get_next_line(const int fd, char **line)
{
	size_t				ret;
	int					len = 0;
	char				*tmp;
	static t_struct		*list;

	if (!fd || !line)
		return (-1);
	printf("check fd\n");
	*line = ft_strnew(0);
	printf("strnew\n");
	if (!list)
	{
		list = (t_struct*)malloc(sizeof(t_struct));
		list->fd = fd;
		list->i = 0;
		printf("allocate new list\n");
	}
	if (list->i != 0)
	{
		printf("check buff before reading i = %lu\n", list->i);
		printf("check buff before reading buf[i] = %s\n", &list->buf[list->i]);
		tmp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(tmp, &list->buf[list->i]);
		printf("line = %s\n", *line);
		free(tmp);
		list->i = 0;
	}
	while ((ret = read(fd, list->buf, BUFF_SIZE)))
	{
		list->buf[ret] = '\0';
		printf("while: list->buf = %s\n", list->buf);
		printf("put 0 at the end of buf\n");
		if (ft_strchr(list->buf, '\n') == NULL)
		{
			printf("if\n");
			tmp = ft_strdup(*line);
			free(*line);
			*line = ft_strjoin(tmp, list->buf);
			printf("line = %s\n", *line);
			free(tmp);
		}
		else
		{
			printf("else\n");
			len = ft_strchr(list->buf, '\n') - list->buf;
			printf("len = %d\n", len);
			list->buf[len] = '\0';
			tmp = ft_strdup(*line);
			free(*line);
			*line = ft_strjoin(tmp, list->buf);
			printf("line = %s\n", *line);
			free(tmp);
			list->i = len + 1;
			break ;
		}
	}
	return (1);	
}
