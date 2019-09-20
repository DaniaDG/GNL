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
	size_t				i = 0;
	int					len = 0;
	char				*tmp;
	static t_struct		*list;

	if (!fd || !line)
		return (-1);
	printf("check fd\n");
	*line = ft_strnew(0);
	printf("strnew\n");
	while ((ret = read(fd, list->buf, BUFF_SIZE)))
	{
		printf("while\n");
		list->buf[ret] = '\0';
		printf("put 0 at the rnd of buf\n");
		if (ft_strchr(list->buf, '\n') == NULL)
		{
			printf("if\n");
			tmp = ft_strdup(*line);
			free(*line);
			*line = ft_strjoin(tmp, list->buf);
			free(tmp);
		}
		else
		{
			printf("else\n");
			len = ft_strchr(list->buf, '\n') - list->buf;
			list->buf[len] = '\0';
			tmp = ft_strdup(*line);
			free(*line);
			*line = ft_strjoin(tmp, list->buf);
			free(tmp);
		}
	}
	return (1);	
}
