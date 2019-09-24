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

int		refresh_str(char **line, char **str)
{
	size_t	i;
	char	*tmp;

	i = ft_strchr(*str, '\n') - *str;
	(*str)[i] = '\0';
	tmp = ft_strdup(*line);
	*line = ft_strjoin(tmp, *str);
	free(tmp);
	tmp = ft_strdup(&(*str)[i + 1]);
	free(*str);
	*str = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int		check_buf(char **line, char *buf, char **str)
{
	size_t		len;
	size_t		i;
	char		*tmp;

	i = ft_strchr(buf, '\n') - buf;
	buf[i] = '\0';
	tmp = ft_strdup(*line);
	*line = ft_strjoin(tmp, buf);
	free(tmp);
	*str = ft_strdup(&buf[i + 1]);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int					ret;
	int					a;
	char				buf[BUFF_SIZE + 1];
	static char			*str;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (!str)
		str = (char*)malloc(sizeof(char));
	if (ft_strchr(str, '\n') != NULL)
		return (a = refresh_str(line, &str));
	else
	{
		*line = ft_strdup(str);
		free (str);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n') == NULL)
			*line = get_line(line, buf);
		else
			return (check_buf(line, buf, &str));
	}
	if (ret == 0)
		return (0);
	return (a);	
}
