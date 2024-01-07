/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:08:10 by mickert           #+#    #+#             */
/*   Updated: 2024/01/07 19:28:46 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	minilib(t_so_long *game)
{
	game->minilib = mlx_init();
	game->window = mlx_new_window(game->minilib, (game->line_length * 100),
			(game->line_counter * 100), "so_long");
	fill_graphics(game);
	mlx_key_hook(game->window, key_press, game);
	mlx_hook(game->window, 17, 0, (void *)exit, 0);
	mlx_loop(game->minilib);
}

void	fill_graphics(t_so_long *game)
{
	int	x;
	int	y;

	game->rocket = mlx_xpm_file_to_image(game->minilib,
			"./graphics/rocket.xpm", &x, &y);
	game->ocean = mlx_xpm_file_to_image(game->minilib,
			"./graphics/ocean.xpm", &x, &y);
	game->island = mlx_xpm_file_to_image(game->minilib,
			"./graphics/island.xpm", &x, &y);
	game->fish = mlx_xpm_file_to_image(game->minilib,
			"./graphics/fish.xpm", &x, &y);
	game->dolphin = mlx_xpm_file_to_image(game->minilib,
			"./graphics/dolphin.xpm", &x, &y);
	fill_window(game);
}

void	fill_window(t_so_long *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->line_counter)
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->minilib, game->window, game->ocean, x
				* 100, y * 100);
			set_map_to_pec(game, y, x);
			x++;
		}
		y++;
	}
}

void	set_map_to_pec(t_so_long *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->minilib, game->window, game->island, x
			* 100, y * 100);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->minilib, game->window, game->dolphin, x
			* 100, y * 100);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->minilib, game->window, game->fish, x
			* 100, y * 100);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->minilib, game->window, game->rocket, x
			* 100, y * 100);
	if (game->map[y][x] == 'e')
	{
		mlx_put_image_to_window(game->minilib, game->window, game->rocket, x
			* 100, y * 100);
		mlx_put_image_to_window(game->minilib, game->window, game->dolphin, x
			* 100, y * 100);
	}
}
