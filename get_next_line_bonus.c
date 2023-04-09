/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:13:31 by makurz            #+#    #+#             */
/*   Updated: 2023/04/09 10:47:56 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Main function body of get_next_line
// First 'if' statement checks for valid inputs
// While loop is there for creating the new new_line
// and also filling the stash for keeping string after the new_line
char	*get_next_line(int fd)
{
	static char	stash[MAX_FD][BUFFER_SIZE + 1];
	t_gnl		next;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > MAX_FD)
		return (NULL);
	next.new_line = NULL;
	while (stash[fd][0] != '\0' || read(fd, stash[fd], BUFFER_SIZE) > 0)
	{
		next.new_line = ft_strjoin(next.new_line, stash[fd], next);
		if (ft_clean_stash(stash[fd], next) == TRUE)
			break ;
		if (read(fd, stash[fd], 0) < 0)
		{
			free(next.new_line);
			return (NULL);
		}
	}
	return (next.new_line);
}
