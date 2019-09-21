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

	printf("OK\n");
	if(!(line = (char**)malloc(sizeof(char*)*5)))
		return (1);
	printf("OK\n");
	fd = open(argv[1], O_RDONLY);
	printf("OK\n");
	gnl = get_next_line(fd, &line[0]);
	printf("%d\n", gnl);
	printf("RESULT = %s\n", line[0]);
	//printf("%d\n", gnl);
	gnl = get_next_line(fd, &line[1]);
	printf("RESULT = %s\n", line[1]);
	gnl = get_next_line(fd, &line[2]);
	printf("RESULT = %s\n", line[2]);
	gnl = get_next_line(fd, &line[3]);
	printf("RESULT = %s\n", line[3]);
	//printf("%s\n", line[2]);
	//printf("%s\n", line[3]);
	return (0);
}
