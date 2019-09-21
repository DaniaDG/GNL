/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:37:33 by bsausage          #+#    #+#             */
/*   Updated: 2019/09/14 11:37:34 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		gnl;
	char	**line;

	if(!(line = (char**)malloc(sizeof(char*)*9)))
		return (1);
	fd = open(argv[1], O_RDONLY);

	gnl = get_next_line(fd, &line[0]);
	printf("RESULT = %s\n", line[0]);
	gnl = get_next_line(fd, &line[1]);
	printf("RESULT = %s\n", line[1]);
	gnl = get_next_line(fd, &line[2]);
	printf("RESULT = %s\n", line[2]);
	gnl = get_next_line(fd, &line[3]);
	printf("RESULT = %s\n", line[3]);
	gnl = get_next_line(fd, &line[4]);
	printf("RESULT = %s\n", line[4]);
	gnl = get_next_line(fd, &line[5]);
	printf("RESULT = %s\n", line[5]);
	gnl = get_next_line(fd, &line[6]);
	printf("RESULT = %s\n", line[6]);
	gnl = get_next_line(fd, &line[7]);
	printf("RESULT = %s\n", line[7]);
	gnl = get_next_line(fd, &line[8]);
	printf("RESULT = %s\n", line[8]);
	return (0);
}
