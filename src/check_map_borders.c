/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	zero_edges(t_game *game)
{
	char	c;

	game->map->y = 0;
	c = 0; //HERE TO MODIFY MAYBE (Faites le !)
	while (game->map->y_size > game->map->y)
	{
		game->map->x = 0;
		while (c != '\0' || game->map->x == 0)
		{
			c = game->map->map[game->map->y][game->map->x];
			if (c == '0')
			{
				if (!game->map->map[game->map->y + 1][game->map->x] ||
					!game->map->map[game->map->y - 1][game->map->x] ||
						!game->map->map[game->map->y][game->map->x + 1] ||
							!game->map->map[game->map->y][game->map->x - 1])
					error("Zero on the edges of the map", game);
			}
			game->map->x++;
		}
		game->map->y++;
	}
	return (SUCCESS);
}

static int	check_top_or_bottom(char **map_tab, int i, int j)
{
	if (!map_tab || !map_tab[i] || !map_tab[i][j])
		return (FAILURE);
	while (map_tab[i][j] == ' ' || map_tab[i][j] == '\t'
	|| map_tab[i][j] == '\r' || map_tab[i][j] == '\v'
	|| map_tab[i][j] == '\f')
		j++;
	while (map_tab[i][j])
	{
		if (map_tab[i][j] != '1')
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

int	check_map_sides(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	if (check_top_or_bottom(map_tab, 0, 0) == FAILURE)
		return (FAILURE);
	i = 1;
	while (i < (game->map->y_size - 1))
	{
		j = ft_strlen(map_tab[i]) - 1;
		if (map_tab[i][j] != '1')
			return (FAILURE);
		i++;
	}
	if (check_top_or_bottom(map_tab, i, 0) == FAILURE)
		return (FAILURE);
	if (zero_edges(game) == SUCCESS)
		return (SUCCESS);
	return (0);
}
