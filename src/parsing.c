/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	before_map(char *str, t_game *game, int n)
{
	int	i;

	i = 0;
	while (str && str[i] == ' ')
		i++;
	if (str && str[i] == 'N')
		n = north(str, i, n, game);
	else if (str && str[i] == 'S')
		n = south(str, i, n, game);
	else if (str && str[i] == 'E')
		n = east(str, i, n, game);
	else if (str && str[i] == 'W')
		n = west(str, i, n, game);
	else if (str && str[i] == 'F')
		n = ft_floor(str, i, game, n);
	else if (str && str[i] == 'C')
		n = ceiling(str, i, game, n);
	else if (str[i] != '\n')
		error("Error unknown character", game);
	return (n);
}

int	parsing(t_game *game)
{
	int		fd;
	char	*tmp;
	int		n;
	int		i;

	i = 0;
	n = 0;
	fd = open (game->argv[1], O_RDWR);
	if (fd == -1)
		error("Error could not open map", game);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		exit(42);
	while (tmp && n < 6)
	{
		n = before_map(tmp, game, n);
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp == NULL)
			exit(42);
		i++;
	}
	free(tmp);
	close(fd);
	return (i);
}
