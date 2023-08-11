/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_fonction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:20:02 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/11 12:45:06 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// gcc main_test_fonction.c get_next_line.c get_next_line_utils.c get_next_line.h -g && ./a.out

int test_copy_line(int fd, int lenght_to_check);
int test_gnl_read(int fd, char *buff);

int	main(void)
{
	int	fd;
	int lenght;

	fd = open("01", O_RDONLY);

	/* Test pour gnl_read */

	char *buff;
	buff = gnl_read(fd, buff);
//	if (buff == NULL)
//		printf("ERROR WITH gnl_read() !\n");
	printf("buff : %s", buff);

	/* Test pour copy_line */
/*
	printf("------\n");
	printf("Test copy_line()\n");
	printf("------\n");
	printf("Longeur de la copie :\n\n");
	scanf("%d", &lenght);
*/
	return 0;
}

int test_copy_line(int fd, int newline_index)
{
	char *buff = NULL;
	char *copied_line = NULL;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return 1;
	if(!read(fd, buff, BUFFER_SIZE))
		return 1;
	
	copied_line = copy_line(buff, copied_line, newline_index - 1);
	if (!copied_line)
		return 1;
	printf("buff        : %s \ncopied_line : %s\n\n", buff, copied_line);
	free(buff);
	free(copied_line);
	return 0;
	
}

int test_gnl_read(int fd, char *buff)
{
	gnl_read(fd, buff);
	
	return 0;
}