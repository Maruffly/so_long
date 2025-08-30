/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:29:18 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/08/27 16:33:32 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_text(char **text)
{
	if (text && *text)
	{
		free(*text);
		*text = NULL;
	}
}

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*read_line(int fd, char **text)
{
	int				bytes_read;
	char			*tmp;
	char			*new_text;

	bytes_read = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	if (!*text)
		*text = ft_strdup("");
	while (bytes_read && !ft_strchr(*text, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_text(text), free(tmp), NULL);
		tmp[bytes_read] = '\0';
		new_text = ft_strjoin(*text, tmp);
		free_text(text);
		*text = new_text;
		if (!*text)
			return (free(tmp), NULL);
	}
	return (free(tmp), NULL);
}

char	*extract_line(char **text)
{
	char	*buffer;
	char	*line;

	if (!ft_strchr(*text, '\n'))
	{
		line = ft_strdup(*text);
		free (*text);
		*text = NULL;
	}
	else
	{
		line = ft_substr(*text, 0, ft_strchr(*text, '\n') - *text + 1);
		buffer = ft_strdup(ft_strchr(*text, '\n') + 1);
		free(*text);
		*text = buffer;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*readed;

	readed = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(fd, &buffer);
	if (buffer && buffer[0] != 0)
		readed = extract_line(&buffer);
	if (buffer && buffer[0] == 0)
	{
		free(buffer);
		buffer = NULL;
	}
	return (readed);
}

/* int	main()
{
	int	fd;
	char *next_line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error file");
		return (1);
	}
	while ((next_line = get_next_line(fd)) != NULL)
	{
		printf("LINE = %s\n", next_line);
		free(next_line);
	}
	close(fd);
	return (0);
} */
