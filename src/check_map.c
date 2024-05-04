/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int start_pos(int pos, t_game *game, char c)
{
	if (c == 'N')
		game->player->angle = 3 * M_PI / 2;
	if (c == 'S')
		game->player->angle = M_PI / 2;
	if (c == 'E')
		game->player->angle = M_PI;
	if (c == 'W')
		game->player->angle = 0;
	game->player->x_pos = (game->map->x * 64) + 32;
	game->player->y_pos = (game->map->y * 64) + 32;
	return (pos + 1);
}

void	quick_check(t_game *game)
{
	int		pos;
	char	c;

	pos = 0;
	game->map->y = 0;
	c = 0; //HERE C TO MODIFY MAYBE (Faites le !)
	while (game->map->y_size > game->map->y)
	{
		game->map->x = 0;
		while (c != '\0' || game->map->x == 0)
		{
			c = game->map->map[game->map->y][game->map->x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				pos = start_pos(pos, game, c);
			else if (c != '0' && c != '1' && c != ' ' && c != '\0')
			{
				error("Error forbidden char for map", game);
			}
			game->map->x++;
		}
		game->map->y++;
	}
	if (pos != 1)
		error("Error wrong number of starting position", game);
}
