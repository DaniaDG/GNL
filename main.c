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
	int		fd1;
	int		fd2;
	int		gnl;
	char	*line;


	/*if (argc == 1)
	{
		gnl = get_next_line(fd, &line);
		printf("RESULT = %s\n", line);
		printf("gnl = %d\n\n", gnl);

		gnl = get_next_line(fd, &line);
		printf("RESULT = %s\n", line);
		printf("gnl = %d\n\n", gnl);

		gnl = get_next_line(fd, &line);
		printf("RESULT = %s\n", line);
		printf("gnl = %d\n\n", gnl);
		return (0);
	}*/
	fd1 = open(argv[1], O_RDONLY);
	//fd2 = open(argv[2], O_RDONLY);

	line = (char*)malloc(sizeof(char));
	gnl = get_next_line(fd1, &line);
	printf("RESULT = %s\n", line);
	printf("gnl = %d\n\n", gnl);
	free(line);

	line = (char*)malloc(sizeof(char));
	gnl = get_next_line(fd1, &line);
	printf("RESULT = %s\n", line);
	printf("gnl = %d\n\n", gnl);
	free(line);

	line = (char*)malloc(sizeof(char));
	gnl = get_next_line(fd1, &line);
	printf("RESULT = %s\n", line);
	printf("gnl = %d\n\n", gnl);
	free(line);

	line = (char*)malloc(sizeof(char));
	gnl = get_next_line(fd1, &line);
	printf("RESULT = %s\n", line);
	printf("gnl = %d\n\n", gnl);
	free(line);

	line = (char*)malloc(sizeof(char));
	gnl = get_next_line(fd1, &line);
	printf("RESULT = %s\n", line);
	printf("gnl = %d\n\n", gnl);
	free(line);

	line = (char*)malloc(sizeof(char));
	gnl = get_next_line(fd1, &line);
	printf("RESULT = %s\n", line);
	printf("gnl = %d\n\n", gnl);
	free(line);

	/*line = (char*)malloc(sizeof(char));
	gnl = get_next_line(fd, &line);
	printf("RESULT = %s\n", line);
	printf("gnl = %d\n\n", gnl);
	free(line);

	line = (char*)malloc(sizeof(char));
	gnl = get_next_line(fd, &line);
	printf("RESULT = %s\n", line);
	printf("gnl = %d\n\n", gnl);
	free(line);

	line = (char*)malloc(sizeof(char));
	gnl = get_next_line(fd, &line);
	printf("RESULT = %s\n", line);
	printf("gnl = %d\n\n", gnl);
	free(line);*/
	

	return (0);
}
