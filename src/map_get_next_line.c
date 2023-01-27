/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:07:18 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/27 09:42:42 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_save_diff(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	line[i + 1] = '\0';
	return (tmp);
}

static char	*ft_get_line(int fd, char *buff, char *save)
{
	char	*tmp;
	int		i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		else if (i == 0)
			break ;
		buff[i] = '\0';
		if (!save)
			save = ft_calloc(sizeof(char), 1);
		tmp = save;
		save = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = NULL;
		if (ft_strrchr(buff, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buff;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		if (save)
		{
			free(save);
			save = NULL;
		}
		return (NULL);
	}
	buff = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1), 1);
	if (!buff)
		return (NULL);
	line = ft_get_line(fd, buff, save);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	save = ft_save_diff(line);
	return (line);
}
