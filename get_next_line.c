/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:33:58 by bsausage          #+#    #+#             */
/*   Updated: 2019/09/14 11:34:00 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		line_len(char *str)
{
	size_t	i;

	i = 0;
	while (*str++ != '\n')
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	int		i;
	char	buf[BUFF_SIZE];

	i = 0;
	if (fd < 0 || !line)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (!(*line = malloc(sizeof(char)*(line_len(buf) + 1))))
		return (-1);
	while (buf[i] != '\n')
	{
		*line[i] = buf[i];
		i++;
	}
	*line[i] = '\0';
	return (1);
}
