/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:05:02 by mickert           #+#    #+#             */
/*   Updated: 2024/01/07 19:30:38 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	positions_pec(t_so_long *game, int i, int y)
{
	if (game->map[y][i] == 'E')
	{
		game->e++;
	}
	if (game->map[y][i] == 'P')
	{
		game->p_position_length = i;
		game->p_position_counter = y;
		game->p++;
	}
	if (game->map[y][i] == 'C')
		game->c++;
}

void	check_pec(t_so_long *game)
{
	int	i;
	int	y;

	y = 0;
	while (y < game->line_counter)
	{
		i = 0;
		while (game->map[y][i])
		{
			positions_pec(game, i, y);
			i++;
		}
		y++;
	}
	if (game->p != 1 || game->e != 1)
		error(game, 21);
	if (game->c < 1)
		error(game, 25);
}
