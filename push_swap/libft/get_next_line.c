/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drgnvgr <drgnvgr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:44:33 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/23 16:52:29 by drgnvgr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_dup(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_next_line(char *progress)
{
	unsigned int		i;
	unsigned int		j;
	char				*s;

	i = 0;
	j = 0;
	while (progress[i] && progress[i] != '\n')
		i++;
	if (!progress[i])
	{
		free(progress);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen_gnl(progress) - i + 2));
	if (!s)
		return (NULL);
	i++;
	while (progress[i])
		s[j++] = progress[i++];
	free(progress);
	s[j] = '\0';
	return (s);
}

char	*ft_gnl_read(int fd, char *progress)
{
	char	*buf;
	int		res_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	res_read = 1;
	while (!ft_strchr_gnl(progress, '\n') && res_read != 0)
	{
		res_read = read(fd, buf, BUFFER_SIZE);
		if (res_read == -1)
		{	
			free(buf);
			return (NULL);
		}
		buf[res_read] = '\0';
		progress = ft_strjoin_gnl(progress, buf);
	}
	free(buf);
	return (progress);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*progress;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	progress = ft_gnl_read(fd, progress);
	if (progress == NULL)
		return (NULL);
	line = ft_gnl_dup(progress);
	progress = ft_next_line(progress);
	return (line);
}
