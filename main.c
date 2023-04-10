/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:40:41 by makurz            #+#    #+#             */
/*   Updated: 2023/04/10 15:18:48 by makurz           ###   ########.fr       */
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
	fd = open("../get_next_line_tests/multiple_new_line.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("new line: #%s", line);
		free(line);
	}
	return (0);
}
