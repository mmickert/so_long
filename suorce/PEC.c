/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PEC.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:05:02 by mickert           #+#    #+#             */
/*   Updated: 2024/01/04 11:56:44 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	positions_PEC(t_so_long *game, int i, int y)
{
	if (game->map[y][i] == 'E')
	{
		game->E++;
	}
	if (game->map[y][i] == 'P')
	{
		game->P_position_length = i;
		game->P_position_counter = y;
		game->P++;
	}
	if (game->map[y][i] == 'C')
		game->C++;
}

void	check_PEC(t_so_long *game)
{
	int	i;
	int	y;

	y = 0;
	while (y < game->line_counter)
	{
		i = 0;
		while (game->map[y][i])
		{
			positions_PEC(game, i, y);
			i++;
		}
		y++;
	}
	if (game->P != 1 || game->E != 1)
		error(game, 21);
}
