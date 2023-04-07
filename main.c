/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:40:41 by makurz            #+#    #+#             */
/*   Updated: 2023/04/07 19:10:56 by makurz           ###   ########.fr       */
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

	fd = open("./test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("new line: #%s", line);
		free(line);
	}
	return (0);
}
