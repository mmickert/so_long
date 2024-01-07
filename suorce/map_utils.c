/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:39:59 by mickert           #+#    #+#             */
/*   Updated: 2024/01/06 16:40:58 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_allowed_char(char c)
{
	return (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E' || (c >= 9
			&& c <= 13) || c == 32);
}

int	check_map_components(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!is_allowed_char(game->map[i][j]))
				error(game, 24);
			j++;
		}
		i++;
	}
	check_map_walls(game);
	check_pec(game);
	return (0);
}
