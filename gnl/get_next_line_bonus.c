/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:03:07 by agigi             #+#    #+#             */
/*   Updated: 2020/11/22 17:01:02 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int	ft_check_buf(char **s_buf, char **line, int fd)
{
	char *n;

	if (!s_buf[fd])
	{
		*line = ft_strdup("");
		return (1);
	}
	else
	{
		if ((n = ft_strchr(s_buf[fd], '\n')))
		{
			*n++ = '\0';
			*line = ft_strdup(s_buf[fd]);
			ft_strlcpy(s_buf[fd], n, ft_strlen(n) + 1);
		}
		else
		{
			*line = ft_strdup(s_buf[fd]);
			free(s_buf[fd]);
			return (1);
		}
	}
	return (0);
}

static int	ft_check_read(int ret, char **line, char **s_buf, int fd)
{
	if (ret < BUFFER_SIZE && !s_buf[fd] && ret != -1)
		return (0);
	if (ret == -1)
	{
		free(*line);
		return (-1);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char	*s_buf[ARRAY_SIZE];
	char		buffer[BUFFER_SIZE + 1];
	int			flag;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	flag = ft_check_buf(s_buf, line, fd);
	if (flag)
		s_buf[fd] = NULL;
	while (flag && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if ((s_buf[fd] = ft_strchr(buffer, '\n')))
		{
			*s_buf[fd]++ = '\0';
			if (!(s_buf[fd] = ft_strdup(s_buf[fd])))
				return (-1);
			flag = 0;
		}
		if (!(*line = ft_strjoin_free(*line, buffer)))
			return (-1);
	}
	return (ft_check_read(ret, line, s_buf, fd));
}
