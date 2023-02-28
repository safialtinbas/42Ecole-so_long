/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saltinba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:30:10 by saltinba          #+#    #+#             */
/*   Updated: 2023/01/12 17:01:48 by saltinba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		rd_byte;

	buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_byte = 1;
	while (ft_find(str) && rd_byte != 0)
	{
		rd_byte = read(fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[rd_byte] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp_line = ft_read(fd, tmp_line);
	if (!tmp_line)
		return (NULL);
	line = ft_line(tmp_line);
	tmp_line = ft_clean(tmp_line);
	return (line);
}
