/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:25:46 by cnorton-          #+#    #+#             */
/*   Updated: 2023/05/11 21:47:16 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_line_end(char *s)
{
	size_t	i;

	if (!s || !s[0])
		return (EMPTY_STR);
	i = -1;
	while (++i < ft_strlen(s))
	{
		if (s[i] == '\n')
			return (i);
	}
	return (NO_NL);
}

char	*read_to_buff(int fd, char *hold_str)
{
	int			readbyte;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	while(check_line_end(hold_str) != CONTAINS_NL)
	{
		readbyte = read(fd, buffer, BUFFER_SIZE);
		if (readbyte < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (readbyte < BUFFER_SIZE) 
		{
			buffer[readbyte] = '\0';
			hold_str = ft_strjoin(hold_str, buffer);
			break;
		}
		hold_str = ft_strjoin(hold_str, buffer);
	}
	free(buffer);
	return (hold_str);
}

char	*get_next_line(int fd)
{
	static char	*hold_str=NULL;
	char		*tmp_str;
	char		*out;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	hold_str = read_to_buff(fd, hold_str);

	i = check_line_end(hold_str);
	if (i < 0)
	{
		out = ft_strdup(hold_str);
		hold_str[0] = '\0';
		return (out);
	}
	out = malloc(i + 2);
	ft_strlcpy(out, hold_str, i + 2);
	tmp_str = ft_strdup(&hold_str[i + 1]);
	free(hold_str);
	hold_str = tmp_str;
	return out;
}

int	main(void)
{
	int	fd;
	setbuf(stdout, NULL);
	fd = open("big_line_with_nl", O_RDONLY);
	printf("GNL1:%s", get_next_line(fd));
	printf("GNL2:%s", get_next_line(fd));
	printf("GNL3:%s", get_next_line(fd));
	printf("GNL4:%s", get_next_line(fd));
	printf("GNL5:%s", get_next_line(fd));
	printf("GNL6:%s", get_next_line(fd));
	printf("GNL7:%s", get_next_line(fd));
	printf("GNL8:%s", get_next_line(fd));
	close(fd);
	return (0);
}
