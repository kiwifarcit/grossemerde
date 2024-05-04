/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error(char *str, t_game *game)
{
	printf("%s\n", str);
	if (game->free == 1)
		freetab(game->map->map);
	if (game->free_n == 1)
		free(game->map->path_n);
	if (game->free_s == 1)
		free(game->map->path_s);
	if (game->free_e == 1)
		free(game->map->path_e);
	if (game->free_w == 1)
		free(game->map->path_w);
	free(game->map);
	free(game);
	exit (EXIT_FAILURE);
}

void	*freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}
