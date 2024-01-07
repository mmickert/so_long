/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:31:57 by mickert           #+#    #+#             */
/*   Updated: 2024/01/06 18:13:30 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_e(t_so_long *game)
{
	if (game->c_counter == game->c_collected)
	{
		ft_printf("\nYou won! :)\n");
		clean_exit(game);
	}
	else
		check_e_aswd(game);
}

void	check_e_aswd(t_so_long *game)
{
	if (game->flag == 41)
	{
		game->p_position_length += 1;
		game->map[game->p_position_counter][game->p_position_length - 1] = '0';
		game->map[game->p_position_counter][game->p_position_length] = 'e';
	}
	else if (game->flag == 42)
	{
		game->p_position_length -= 1;
		game->map[game->p_position_counter][game->p_position_length + 1] = '0';
		game->map[game->p_position_counter][game->p_position_length] = 'e';
	}
	else if (game->flag == 43)
	{
		game->p_position_counter += 1;
		game->map[game->p_position_counter - 1][game->p_position_length] = '0';
		game->map[game->p_position_counter][game->p_position_length] = 'e';
	}
	else if (game->flag == 44)
	{
		game->p_position_counter -= 1;
		game->map[game->p_position_counter + 1][game->p_position_length] = '0';
		game->map[game->p_position_counter][game->p_position_length] = 'e';
	}
}

void	clean_exit(t_so_long *game)
{
	int	i;

	i = 0;
	while (i < game->line_counter && game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (game->island)
		mlx_destroy_image(game->minilib, game->island);
	if (game->fish)
		mlx_destroy_image(game->minilib, game->fish);
	if (game->ocean)
		mlx_destroy_image(game->minilib, game->ocean);
	if (game->rocket)
		mlx_destroy_image(game->minilib, game->rocket);
	if (game->dolphin)
		mlx_destroy_image(game->minilib, game->dolphin);
	if (game->window)
		mlx_destroy_window(game->minilib, game->window);
	exit(0);
}
