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
#include "libft/libft.h"

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
	ft_memdel((void**)str);
	if (!(*str = ft_strdup(tmp)))
		return (-1);
	ft_memdel((void**)&tmp);
	return (1);
}

static char		*add_buff(int fd, char **str, int *ret)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	*ret = read(fd, buf, BUFF_SIZE);
	buf[*ret] = '\0';
	tmp = ft_strdup(*str);
	ft_memdel((void**)str);
	*str = ft_strjoin(tmp, buf);
	ft_memdel((void**)&tmp);
	return (*str);
}

int				get_last_line(char **line, char **str)
{
	if (!(*line = ft_strdup(*str)))
		return (-1);
	ft_memdel((void**)str);
	return (1);
}

t_struct		*find_fd(t_struct **b_list, int fd)
{
	t_struct	*ptr;
	t_struct	*tmp;

	ptr = *b_list;
	if (!ptr)
	{
		tmp = (t_struct *)malloc(sizeof(t_struct));
		tmp->fd = fd;
		tmp->str = NULL;
		tmp->next = NULL;
		*b_list = tmp;
		return(*b_list);
	}
	while (ptr)
	{
		if (ptr->fd == fd)
			return (ptr);
		tmp = ptr;
		ptr = ptr->next;
	}
	tmp->next = (t_struct *)malloc(sizeof(t_struct));
	tmp->next->fd = fd;
	tmp->next->str = NULL;
	tmp->next->next = NULL;
	return(tmp->next);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	t_struct		*current;
	static t_struct	*list;

	ret = 1;
	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	current = find_fd(&list, fd);
	while (ret > 0)
	{
		if (!current->str)
			current->str = ft_strnew(0);
		if (ft_strchr(current->str, '\n'))
			return (read_from_str(line, &(current->str)));
		if (!(current->str = add_buff(fd, &(current->str), &ret)))
			return (-1);
	}
	if (!ret && current->str)
		return (get_last_line(line, &(current->str)));
	if (!ret)
		ft_memdel((void**)&(current->str));
	return (0);
}
