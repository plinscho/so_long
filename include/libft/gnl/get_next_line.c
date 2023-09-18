/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:30:01 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/09 20:30:05 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*read_storage(int fd, char *storage)
{
	char	*temp_storage;
	int		read_bytes;

	temp_storage = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_storage)
		return (free_storage(storage));
	read_bytes = 42;
	while (!ft_strchr_gnl(storage, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, temp_storage, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(temp_storage);
			if (storage)
				free(storage);
			return (NULL);
		}
		temp_storage[read_bytes] = '\0';
		storage = ft_strjoin_gnl(storage, temp_storage);
	}
	free(temp_storage);
	temp_storage = NULL;
	return (storage);
}

static char	*extract_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (storage[0] == '\0')
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static void	*clean_storage(char *storage)
{
	int		i;
	int		j;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = malloc(sizeof(char) * (ft_strlen_gnl(storage) - i + 1));
	if (!new_storage)
	{
		free(storage);
		return (NULL);
	}
	i++;
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(storage);
		return (NULL);
	}
	if (!storage || (storage && !ft_strchr_gnl(storage, '\n')))
		storage = read_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = clean_storage(storage);
	return (line);
}
