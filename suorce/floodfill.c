/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:05:17 by mickert           #+#    #+#             */
/*   Updated: 2024/01/06 16:48:21 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill_recursive(t_so_long *game, int start_length, int start_counter,
		int filled[][game->line_counter])
{
	if (start_length < 0 || start_length >= game->line_length
		|| start_counter < 0 || start_counter >= game->line_counter
		|| game->map[start_counter][start_length] == '1'
		|| filled[start_length][start_counter])
		return (0);
	filled[start_length][start_counter] = 1;
	if (game->map[start_counter][start_length] == 'C')
		game->c_counter++;
	else if (game->map[start_counter][start_length] == 'E')
		game->e_reachable = 1;
	flood_fill_recursive(game, start_length + 1, start_counter, filled);
	flood_fill_recursive(game, start_length - 1, start_counter, filled);
	flood_fill_recursive(game, start_length, start_counter + 1, filled);
	flood_fill_recursive(game, start_length, start_counter - 1, filled);
	return (1);
}

void	flood_fill(t_so_long *game)
{
	int	filled[100][100];
	int	start_length;
	int	start_counter;

	start_length = game->p_position_length;
	start_counter = game->p_position_counter;
	ft_memset(filled, 0, sizeof(filled));
	flood_fill_recursive(game, start_length, start_counter, filled);
	if (game->e_reachable != 1)
		error(game, 20);
	if (game->c_counter != game->c)
		error(game, 19);
}
