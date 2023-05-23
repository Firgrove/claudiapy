/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:07:13 by cnorton-          #+#    #+#             */
/*   Updated: 2023/05/11 21:47:18 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
//I am playing around with strjoin so that 
//I can call it on the first and subsequent 
//calls of GNL. For now I am 

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	l;
	char	*new;

	if (!s1)
	{
		return (ft_strdup(s2));
	}	
	l = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(l + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, l + 1);
	ft_strlcat(new, s2, l + 1);
	free(s1);
	return (new);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1);
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len * sizeof(char) + 1);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	j = len_dst;
	if (dstsize > 0 && j < dstsize)
	{
		while (src[i] != '\0' && i < (dstsize - j - 1))
		{
			dst[j + i] = src[i];
			i++;
		}
		dst[j + i] = '\0';
	}
	if (dstsize > len_dst)
		return (len_dst + ft_strlen(src));
	else
		return (ft_strlen(src) + dstsize);
}
