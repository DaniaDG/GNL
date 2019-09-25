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

int		check_str(char **line, char **str)
{
	int		len;
	char	*tmp;

	if (!(*str))
		return (0);
	if (ft_strchr(*str, '\n') == NULL)
	{
		*line = get_line(line, *str);
		//printf("if: check line = %s\n", *line);
		free(*str);
		//printf("free str OK\n");
		return (0);
	}
	else
	{
		//printf("check str = %s\n", *str);
		len = ft_strchr(*str, '\n') - *str;
		(*str)[len] = '\0';
		//printf("put 0terminator into str = %s\n", *str);
		*line = get_line(line, *str);
		//printf("else: check line = %s\n", *line);
		tmp = ft_strdup(&(*str)[len + 1]);
		//printf("else: check tmp = %s\n", tmp);
		free(*str);
		//printf("free str OK\n");
		*str = ft_strdup(tmp);
		//printf("check str = %s\n", *str);
		free(tmp);
	}
	if (*line == NULL)
		return (-1);
	return (1);
}

int		check_buf(char **line, char *buf, int ret, char	**str)
{
	int		len;

	if (!ret)
		return (0);
	if (ft_strchr(buf, '\n') == NULL)
		{
			*line = get_line(line, buf);
			//printf("while line = %s\n", *line);
		}
		else
		{
			len = ft_strchr(buf, '\n') - buf;
			buf[len] = '\0';
			*line = get_line(line, buf);
			//printf("while line = %s\n", *line);
			*str = ft_strdup(&buf[len + 1]);
			//printf("while str = %s\n", list->str);
		}
	if (*line == NULL)
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	size_t				ret;
	int					a;
	char				buf[BUFF_SIZE + 1];
	static char			*str;
	//t_struct			*curr_list;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (!str)
		str = (char*)malloc(sizeof(char));
	if ((a = check_str(line, &str)))
		return (a);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((a = check_buf(line, buf, ret, &str)))
			return (a);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	return (a);	
}
