/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:09:22 by makurz            #+#    #+#             */
/*   Updated: 2023/04/09 10:43:34 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TRUE 1
# define FALSE 0

# ifndef MAX_FD
#  define MAX_FD 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_gnl
{
	char	*new_line;
	size_t	i;
	size_t	k;
}	t_gnl;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, t_gnl str);
int		ft_clean_stash(char *str, t_gnl next);

#endif // GET_NEXT_LINE_BONUS_H
