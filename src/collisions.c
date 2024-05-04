/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	search_player_pos(t_game *game, int i, int j)
{
	while (game->map->map[j])
	{
		i = 0;
		while (i < game->map->x_size - 1)
		{
			if (game->map->map[j][i] == 'N' || game->map->map[j][i] == 'S'
				|| game->map->map[j][i] == 'E' || game->map->map[j][i] == 'W')
			{
				game->player->x_pos = i + 0.5;
				game->player->y_pos = j + 0.5;
				if (game->map->map[j][i] == 'N')
					game->player->angle = 3 * M_PI / 2;
				if (game->map->map[j][i] == 'S')
					game->player->angle = M_PI / 2;
				if (game->map->map[j][i] == 'E')
					game->player->angle = 0;
				if (game->map->map[j][i] == 'W')
					game->player->angle = M_PI;
			}
			i++;
		}
		j++;
	}
}

void	collision(t_game *game, float col[2], float x, float y)
{
	int		t;

	t = 0;
	if (game->map->map[(int)(y + col[1] * 2)][(int)(x + col[0] * 2)] != '1')
	{
		if (col[0] > 0 && col[1] > 0 && game->map->map[(int)(y + 0.4)]
			[(int)(x + 0.4)] != '1')
			t = 1;
		else if (col[0] < 0 && col[1] > 0
			&& game->map->map[(int)(y + 0.4)][(int)(x - 0.4)] != '1')
			t = 1;
		else if (col[0] > 0 && col[1] < 0
			&& game->map->map[(int)(y - 0.4)][(int)(x + 0.4)] != '1')
			t = 1;
		else if (col[0] < 0 && col[1] < 0
			&& game->map->map[(int)(y - 0.4)][(int)(x - 0.4)] != '1')
			t = 1;
	}
	if (t)
	{
		game->player->x_pos += col[0] * 3;
		game->player->y_pos += col[1] * 3;
	}
}

float	*get_move(t_game *game, float col[2])
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		col[0] = cos(game->player->angle) * 0.2;
		col[1] = sin(game->player->angle) * 0.2;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		col[0] = -cos(game->player->angle) * 0.2;
		col[1] = -sin(game->player->angle) * 0.2;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		col[0] = -sin(game->player->angle) * 0.2;
		col[1] = cos(game->player->angle) * 0.2;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		col[0] = sin(game->player->angle) * 0.2;
		col[1] = -cos(game->player->angle) * 0.2;
	}
	return (col);
}