/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:48:00 by ktaplin           #+#    #+#             */
/*   Updated: 2022/11/23 14:38:25 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_color_f(char *number, int cpt, t_game *game)
{
	if (cpt == 1)
		game->floor_r = ft_atoi(number);
	if (cpt == 2)
		game->floor_g = ft_atoi(number);
	if (cpt == 3)
		game->floor_b = ft_atoi(number);
}

int	floor_utils_two(t_game *game, char *number)
{
	game->j_rgb++;
	if (game->j_rgb > 3)
	{
		free(number);
		error("Error wrong RGB value", game);
	}
	return (game->j_rgb);
}

int	floor_utils_three(t_game *game, int i, char *number, char *str)
{
	number[game->j_rgb] = str[i];
	i++;
	game->j_rgb = floor_utils_two(game, number);
	return (i);
}

char	*floor_utils(char *number, int cpt)
{
	if (cpt < 3)
	{
		free (number);
		number = malloc(sizeof (char) * 5);
	}
	return (number);
}

int	ft_floor(char *str, int i, t_game *game, int n)
{
	char	*number;
	int		cpt;

	cpt = check_fc(str, 'F', game);
	number = malloc(sizeof (char) * 5);
	while (str[++i] == ' ')
		;
	while (str[i] && str[i] != '\n')
	{	
		while (ft_isdigit(str[i]) == 0)
			i = floor_utils_three(game, i, number, str);
		game->j_rgb = 0;
		set_color_f(number, ++cpt, game);
		number = floor_utils(number, cpt);
		while (str[i] == ' ')
			i++;
		if (str[i] == ',')
			i++;
		while (str[i] == ' ')
			i++;
	}
	free(number);
	return (n + 1);
}
