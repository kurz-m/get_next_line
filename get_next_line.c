/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:03:53 by makurz            #+#    #+#             */
/*   Updated: 2023/04/06 22:23:22 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

// functions I want to include:
// ft_get_new_line();
// ft_stash_remainder();

static	char *ft_stash_remainder(char **stash, int i)
{
	char	*new_stash;

	if (!*stash[i])
		return (free(*stash), NULL);
	new_stash = malloc((ft_strlen(*stash) - i) * sizeof(char));
	if (new_stash == NULL)
		return (*stash = NULL, NULL);
	
	return new_stash;
}
// 0 1 2 3 4 5 6 7 8 9
//        \n          
static char *ft_get_new_line(char **extract_newline)
{
	char	*new_line;
	int		i;

	if (!*extract_newline || *extract_newline[0] == '\0')
		return (NULL);
	i = 0;
	while (*extract_newline[i] != '\n' || *extract_newline[i] != '\0')
		++i;
	new_line = malloc((i + 1) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	ft_memcpy(new_line, *extract_newline, i);
	return (new_line);
}

static char	*ft_read_buffer(char *stash_remainder, int fd)
{
	char	*tmp_stash;
	size_t	bytes_read;

	tmp_stash = NULL;
	tmp_stash = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp_stash == NULL)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(stash_remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, tmp_stash, BUFFER_SIZE);
		if (bytes_read == 0)
			return (free(tmp_stash), free(stash_remainder), NULL);
		tmp_stash[bytes_read] = '\0';
		stash_remainder = ft_strjoin(stash_remainder, tmp_stash);
	}
	return (free(tmp_stash), stash_remainder);
}

char	*get_next_line(int fd)
{
	char	*stash_remainder[MAX_FD];
	char	*new_line;

	if (BUFFER_SIZE <= 0 || fd > MAX_FD || fd < 0)
		return (NULL);
	new_line = NULL;
	stash_remainder[fd] = ft_read_buffer(stash_remainder[fd], fd);
	new_line = ft_get_new_line(&stash_remainder[fd]);
	return (new_line);
}
