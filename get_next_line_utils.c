/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:34:06 by makurz            #+#    #+#             */
/*   Updated: 2023/04/06 14:53:32 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Returns the first occurrence of the character 'c' in the string 's'.
char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr)
	{
		if (*ptr == (unsigned char) c)
			return (ptr);
		ptr++;
	}
	if (*ptr == (unsigned char) c)
		return (ptr);
	return (0);
}

// Returns the length of the string 's'.
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

// Returns a freeable string 'dst', which is concatenated from 's1' and 's2'.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int			i;
	size_t		dst_len;
	size_t		src_len;

	i = -1;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		return (dstsize + src_len);
	if (dstsize > 0)
		dstsize--;
	while (src[++i] && dst_len + i < dstsize)
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// Copies 'n' bytes from memory space 'src' to memory space 'dst'.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*tmp_src;
	char		*tmp_dst;

	i = 0;
	if (!dst && !src)
		return (dst);
	tmp_src = (const char *) src;
	tmp_dst = (char *) dst;
	while (i++ < n)
		*tmp_dst++ = *tmp_src++;
	return (dst);
}

// Returns a freeable string 'dst', which is concatenated from 's1' and 's2'.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;
	size_t	dstsize;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dstsize = len_s1 + len_s2 + 1;
	dst = (char *) malloc(sizeof(char) * dstsize);
	if (!dst)
		return (0);
	dst = ft_memcpy(dst, s1, len_s1 + 1);
	ft_strlcat(dst, s2, dstsize);
	return (dst);
}
