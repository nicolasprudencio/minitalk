/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:52 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/23 16:35:57 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*st_readtol(int fd, char *memory);
static char	*st_findl(char *memory);
static char	*st_findnextl(char *memory);

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!memory)
	{
		memory = (char *)fp_calloc(1, sizeof(char));
		if (!memory)
			return (NULL);
	}
	memory = st_readtol(fd, memory);
	line = st_findl(memory);
	if (!line)
	{
		free(memory);
		memory = NULL;
		return (NULL);
	}
	memory = st_findnextl(memory);
	return (line);
}

static char	*st_readtol(int fd, char *memory)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)fp_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (fp_strchr(buffer, '\n') == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free(buffer);
			free(memory);
			return (NULL);
		}
		memory = fp_strjoin(memory, buffer, 1);
	}
	free(buffer);
	return (memory);
}

static char	*st_findl(char *memory)
{
	int		i;
	int		j;
	int		check;
	char	*line;

	i = 0;
	j = -1;
	check = 0;
	if (!memory || memory[0] == '\0')
		return (NULL);
	while (memory[i] != '\n' && memory[i])
		i++;
	if (fp_strchr(memory, '\n'))
		check++;
	line = (char *)fp_calloc(i + check + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (++j < (i + check))
		line[j] = memory[j];
	return (line);
}

static char	*st_findnextl(char *memory)
{
	int	size;
	int	start;

	size = 0;
	start = 0;
	if (!memory)
		return (NULL);
	while (memory[size] != '\0')
	{
		if (memory[size] == '\n' && start == 0)
			start = size + 1;
		size++;
	}
	if (!start)
	{
		free(memory);
		return (NULL);
	}
	memory = fp_cutstr(memory, start, (size - start));
	return (memory);
}
