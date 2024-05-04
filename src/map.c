/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*map_size_utils(t_game *game, int fd, char *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		game->map->y_size++;
		while (tmp[i] != '\n' && tmp[i] != '\0')
			i++;
		if (i > game->map->x_size)
			game->map->x_size = i;
		free(tmp);
		tmp = get_next_line(fd);
		i = 0;
	}
	return (tmp);
}

void	map_size(t_game *game, int n)
{
	int		fd;
	char	*tmp;
	int		i;

	i = 0;
	fd = open (game->argv[1], O_RDWR);
	if (fd == -1)
		error("Error could not open map", game);
	tmp = get_next_line(fd);
	while (i != n)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	tmp = map_size_utils(game, fd, tmp);
	free(tmp);
	close(fd);
}

void	save_map(char *str, t_game *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	game->map->map[game->map->y++] = str;
	game->free = 1;
}

void	map_bis(t_game *game)
{
	game->map->map[game->map->y] = NULL;
	quick_check(game);
	if (check_map_sides(game, game->map->map) == -1)
		error("Error map edges", game);
}

void	map(t_game *game, int i)
{
	int		fd;
	char	*tmp;
	int		n;

	n = 0;
	fd = open (game->argv[1], O_RDWR);
	if (fd == -1)
		error("Error could not open map", game);
	tmp = get_next_line(fd);
	while (n <= i || line_empty(tmp) == 1)
	{
		free(tmp);
		tmp = get_next_line(fd);
		n++;
	}
	map_size(game, n);
	game->map->map = malloc ((game->map->y_size + 1) * sizeof (char *));
	while (tmp)
	{
		save_map(tmp, game);
		tmp = get_next_line(fd);
	}
	map_bis(game);
	free(tmp);
	close(fd);
}
