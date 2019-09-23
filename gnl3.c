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

int		check_str(char **line, char **str)
{
	size_t		len;
	size_t		i;
	char		*tmp;

	printf("check str BEGIN\n");
	printf("check str: str = %s\n", *str);
	if (*str == NULL)
		return (0);
	printf("check str: str = %s\n", *str);
	if (ft_strchr(*str, '\n') == NULL)
	{
		*line = ft_strdup(*str);
		printf("check str if: line = %s\n", *line);
		free(*str);
		return (2);
	}
	else
	{
		i = ft_strchr(*str, '\n') - *str;
		len = ft_strlen(*line) + i + 1;
		*line = (char*)realloc(*line, len);
		(*line)[len] = '\0';
		*line = ft_strncpy(*line, *str, i);
		printf("check str else: line = %s\n", *line);
		tmp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		*str = ft_strdup(tmp);
		printf("check str else: str = %s\n", *str);
		free(tmp);
	}
	if (*line == NULL)
		return (-1);
	return (1);
}

int		check_buf(char **line, char *buf, int ret, t_struct **list)
{
	size_t		len;
	size_t		i;

	printf("check buf BEGIN\n");
	//if (!ret)
	//	return (0);
	if (ft_strchr(buf, '\n') == NULL)
	{
		*line = ft_strdup(buf);
		printf("check buf if: line = %s\n", *line);
		return (0);
	}
	else
	{
		i = ft_strchr(buf, '\n') - buf;
		len = ft_strlen(*line) + i + 1;
		*line = (char*)realloc(*line, len);
		(*line)[len] = '\0';
		*line = ft_strncat(*line, buf, i);
		printf("check buf else: line = %s\n", *line);
		(*list)->str = ft_strdup(&buf[i + 1]);
		printf("check buf else: str = %s\n", (*list)->str);
	}
	if (*list == NULL)
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	size_t				ret;
	int					a;
	char				buf[BUFF_SIZE + 1];
	static t_struct		*list;
	//t_struct			*curr_list;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	if (!list)
	{
		if (!(list = (t_struct*)malloc(sizeof(t_struct))))
			return (-1);
		list->str = NULL;
		list->fd = fd;
	}
	a = check_str(line, &list->str);
	if (a != 0 && a != 2)
		return (a);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((a = check_buf(line, buf, ret, &list)))
		{
			printf("BUFF: %s\n", buf);
			return (a);
		}
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	if (a == 0 && ret == 0)
		return (1);
	return (a);	
}
