/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_prepare_next_line(char *str)
{
	int		i;
	char	*next_line;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == 0)
	{
		free(str);
		return (NULL);
	}
	next_line = ft_substr(str, i + 1, ft_strlen(str));
	free(str);
	return (next_line);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != 0)
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
}

char	*ft_read_line(int fd, char *str)
{
	char	*buf;
	int		check_read;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	check_read = 1;
	while (check_read > 0 && !ft_strchr(buf, '\n'))
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[check_read] = 0;
		if (check_read != 0)
			str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_line(fd, str);
	if (!str)
		return (NULL);
	ret_line = ft_get_line(str);
	str = ft_prepare_next_line(str);
	return (ret_line);
}
