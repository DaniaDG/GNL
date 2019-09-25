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

static int		read_from_str(char **line, char **str)
{
	size_t	i;
	char	*tmp;

	i = ft_strchr(*str, '\n') - *str;
	(*str)[i] = '\0';
	if (!(*line = ft_strdup(*str)))
		return (-1);
	if (!(tmp = ft_strdup(&(*str)[i + 1])))
		return (-1);
	free(*str);
	if (!(*str = ft_strdup(tmp)))
		return (-1);
	free(tmp);
	return (1);
}

static char		*add_buff(int fd, char **str, int *ret)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	*ret = read(fd, buf, BUFF_SIZE);
	buf[*ret] = '\0';
	tmp = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(tmp, buf);
	free(tmp);
	return (*str);
}

int				get_last_line(char **line, t_struct **current)
{
	t_struct	*tmp;

	if (!(*line = ft_strdup((*current)->str)))
		return (-1);
	free((*current)->str);
	tmp = (*current)->next;
	free(*current);
	*current = tmp;
	return (1);
}

static t_struct		*find_fd(t_struct *begin_list, int fd)
{
	t_struct	*list;

	list = begin_list;
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	if (!(list = (t_struct*)malloc(sizeof(t_struct))))
		return (NULL);
	list->fd = fd;
	list->str = NULL;
	list->next = NULL;
	return (list);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	static t_struct	*begin_list;
	t_struct		*current;

	ret = 1;
	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!begin_list)
	{
		if (!(begin_list = (t_struct*)malloc(sizeof(t_struct))))
			return (-1);
		begin_list->fd = fd;
		begin_list->str = NULL;
		begin_list->next = NULL;
	}
	if (!(current = find_fd(begin_list, fd)))
		return (-1);
	while (ret > 0)
	{
		if (!(current->str))
			current->str = ft_strnew(0);
		if (ft_strchr(current->str, '\n'))
			return (read_from_str(line, &(current->str)));
		if (!(current->str = add_buff(fd, &(current->str), &ret)))
			return (-1);
	}
	if (!ret && ft_strlen(current->str))
		return (get_last_line(line, &current));
	return (0);
}
