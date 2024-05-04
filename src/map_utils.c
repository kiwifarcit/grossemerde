/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->y_size > i)
	{
		printf("%s\n", game->map->map[i]);
		i++;
	}
}

int	line_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

int	check_fc(char *str, char cf, t_game *game)
{
	int	nb;
	int	i;

	game->j_rgb = 0;
	i = 0;
	nb = 0;
	while (str[i] != cf)
		i++;
	i++;
	while (str[i])
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			error("Error wrong character", game);
		if (ft_isdigit(str[i]) == 0)
		{
			nb++;
			while (ft_isdigit(str[i]) == 0)
				i++;
		}
		i++;
	}
	if (nb != 3)
		error("Error wrong number of arguments in floor/ceiling", game);
	return (0);
}

void	check_rgb(t_game *game)
{
	if (game->ceiling_r < 0 || game->ceiling_g < 0 || game->ceiling_b < 0
		|| game->floor_r < 0 || game->floor_g < 0 || game->floor_b < 0
		|| game->ceiling_r > 255 || game->ceiling_g > 255
		|| game->ceiling_b > 255
		|| game->floor_r > 255 || game->floor_g > 255 || game->floor_b > 255)
		error("Error wrong RGB value", game);
}
