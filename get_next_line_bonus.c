/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:05:00 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/10 02:09:22 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_buffer(int fd)
{
	char	*buffer;
	int		bytesread;

	buffer = malloc((size_t)1);
	if (!buffer)
		return (NULL);
	bytesread = read(fd, buffer, 1);
	if (bytesread <= 0)
		return (cleanup (&buffer), NULL);
	buffer[bytesread] = '\0';
	return (buffer);
}

char	*rest_line(char *line, char **rest, int i)
{
	if (line[i] == '\n')
	{
		*rest = ft_strdup(&line[i + 1]);
		if (!*rest)
			return (cleanup (&line), NULL);
		return (line[i + 1] = '\0', line);
	}
	return (NULL);
}

char	*join_buffer(int fd, char **rest, char *line)
{
	char	*temp;
	int		i;
	char	*buffer;

	while (1)
	{
		buffer = read_buffer (fd);
		if (!buffer)
			break ;
		temp = line;
		line = ft_strjoin (line, buffer);
		cleanup (&buffer);
		if (!line)
			return (cleanup (&temp), NULL);
		cleanup (&temp);
		i = 0;
		while (line[i])
		{
			if (rest_line (line, rest, i))
				return (line);
			i++;
		}
	}
	return (line);
}

char	*handle_remainder(int fd, char **rest, char *line)
{
	int		i;
	char	*new_rest;

	i = 0;
	if (*rest)
	{
		while ((*rest)[i])
		{
			if ((*rest)[i] == '\n')
			{
				line = ft_substr (*rest, 0, i + 1);
				if (!line)
					return (cleanup(rest), NULL);
				new_rest = ft_strdup(&(*rest)[i + 1]);
				cleanup (rest);
				if (!new_rest)
					return (cleanup(&line), NULL);
				return (*rest = new_rest, line);
			}
			i++;
		}
		line = ft_strdup(*rest);
		cleanup (rest);
	}
	return (join_buffer(fd, rest, line));
}

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*line;

	if (fd < 0 || read (fd, 0, 0) < 0)
		return (cleanup (&rest), NULL);
	if (!rest)
		line = ft_strdup ("");
	else
		line = NULL;
	line = handle_remainder (fd, &rest, line);
	if (!line || *line == '\0')
		return (cleanup (&line), NULL);
	return (line);
}
