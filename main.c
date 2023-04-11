/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:40:41 by makurz            #+#    #+#             */
/*   Updated: 2023/04/11 15:04:56 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>

// int main()
// {
// 	char buffer[10];
// 	ssize_t bytes_read;
// 
// 	// Attempt to read 10 bytes from standard input
// 	bytes_read = read(STDIN_FILENO, buffer, 10);
// 
// 	printf("Bytes read: %ld\n", bytes_read);
// 
// 	return 0;
// }

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("./long_nl.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("new line: #%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
//
// int	main(void)
// {
// 	long pos = 0;
// 	FILE* file = fopen("./long_nl.txt", "r");
//     char line[256];
// 
//     if (file==NULL) 
//     {
//         perror ("Error reading file");
//     }
//     else
//     {
//         fseek(file , pos , SEEK_CUR);
//         fgets(line, sizeof(line), file);
//         printf("%s", line);
//     }
//     pos = ftell(file);
//     return (0);
// }
