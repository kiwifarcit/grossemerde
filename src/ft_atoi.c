/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:48:00 by ktaplin           #+#    #+#             */
/*   Updated: 2022/11/23 14:38:25 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_isspace(char c);
static int	int_(const char *str);

int	ft_atoi(const char *str)
{
	int	nb_min;
	int	signe;

	nb_min = 0;
	signe = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			nb_min++;
		str++;
	}
	if (nb_min % 2 != 0)
		signe = -1;
	return (int_(str) * signe);
}

static int	int_(const char *str)
{		
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

static int	ft_isspace(char c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}
