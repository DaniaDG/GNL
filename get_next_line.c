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
#include <stdio.h>

size_t		line_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && i < BUFF_SIZE)
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	size_t		len;
	size_t		i;
	size_t		ret;
	char		*tmp1;
	char		*tmp2;
	char		buf[BUFF_SIZE];


	i = 0;
	if (fd < 0 || !line)
		return (-1);
	while (ret = read(fd, buf, BUFF_SIZE))
	{
		len = line_len(buf);
		if (!(*tmp1 = malloc(sizeof(char)*(len + 1))))
			return (-1);	 
		while (buf[i] != '\n' && i < len)
		{
			tmp1[i] = buf[i];
			i++;
		}
		tmp1[i] = '\0';
		if (len < BUFF_SIZE)
		{
			*line = ft_strdup(tmp1);
			break ;
		}
		
	}
	(*line)[i] = '\0';
	return (1);
}
