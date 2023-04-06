/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:40:41 by makurz            #+#    #+#             */
/*   Updated: 2023/04/06 08:41:04 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main()
{
	char buffer[10];
	ssize_t bytes_read;

	// Attempt to read 10 bytes from standard input
	bytes_read = read(STDIN_FILENO, buffer, 10);

	printf("Bytes read: %ld\n", bytes_read);

	return 0;
}
