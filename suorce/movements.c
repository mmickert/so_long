/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:38:49 by mickert           #+#    #+#             */
/*   Updated: 2024/01/06 18:22:17 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key_pressed, t_so_long *game)
{
	int	temp_pos;

	temp_pos = game->p_position_counter;
	if (key_pressed == 13 || key_pressed == 126)
		key_w(game, temp_pos);
	if (key_pressed == 1 || key_pressed == 125)
		key_s(game, temp_pos);
	temp_pos = game->p_position_length;
	if (key_pressed == 0 || key_pressed == 123)
		key_a(game, temp_pos);
	if (key_pressed == 2 || key_pressed == 124)
		key_d(game, temp_pos);
	if (key_pressed == 53)
		clean_exit(game);
	mlx_clear_window(game->minilib, game->window);
	fill_graphics(game);
	return (0);
}

int	key_d(t_so_long *game, int temp_pos)
{
	if (game->map[game->p_position_counter][temp_pos + 1] == '1')
		return (1);
	if (game->map[game->p_position_counter][temp_pos + 1] == 'E')
	{
		game->flag = 41;
		check_e(game);
	}
	else
	{
		game->p_position_length += 1;
		game->move_counter++;
		ft_printf("Move number %d\n", game->move_counter);
		if (game->map[game->p_position_counter][game->p_position_length] == 'C')
			game->c_collected++;
		if (game->map[game->p_position_counter][game->p_position_length
			- 1] == 'e')
			game->map[game->p_position_counter][game->p_position_length
				- 1] = 'E';
		else
			game->map[game->p_position_counter][game->p_position_length
				- 1] = '0';
		game->map[game->p_position_counter][game->p_position_length] = 'P';
	}
	return (0);
}

int	key_a(t_so_long *game, int temp_pos)
{
	if (game->map[game->p_position_counter][temp_pos - 1] == '1')
		return (1);
	if (game->map[game->p_position_counter][temp_pos - 1] == 'E')
	{
		game->flag = 42;
		check_e(game);
	}
	else
	{
		game->p_position_length -= 1;
		game->move_counter++;
		ft_printf("Move number %d\n", game->move_counter);
		if (game->map[game->p_position_counter][game->p_position_length] == 'C')
			game->c_collected++;
		if (game->map[game->p_position_counter][game->p_position_length
			+ 1] == 'e')
			game->map[game->p_position_counter][game->p_position_length
				+ 1] = 'E';
		else
			game->map[game->p_position_counter][game->p_position_length
				+ 1] = '0';
		game->map[game->p_position_counter][game->p_position_length] = 'P';
	}
	return (0);
}

int	key_s(t_so_long *game, int temp_pos)
{
	if (game->map[temp_pos + 1][game->p_position_length] == '1')
		return (1);
	if (game->map[temp_pos + 1][game->p_position_length] == 'E')
	{
		game->flag = 43;
		check_e(game);
	}
	else
	{
		game->p_position_counter += 1;
		game->move_counter++;
		ft_printf("Move number %d\n", game->move_counter);
		if (game->map[game->p_position_counter][game->p_position_length] == 'C')
			game->c_collected++;
		if (game->map[game->p_position_counter
				- 1][game->p_position_length] == 'e')
			game->map[game->p_position_counter
				- 1][game->p_position_length] = 'E';
		else
			game->map[game->p_position_counter
				- 1][game->p_position_length] = '0';
		game->map[game->p_position_counter][game->p_position_length] = 'P';
	}
	return (0);
}

int	key_w(t_so_long *game, int temp_pos)
{
	if (game->map[temp_pos - 1][game->p_position_length] == '1')
		return (1);
	if (game->map[temp_pos - 1][game->p_position_length] == 'E')
	{
		game->flag = 44;
		check_e(game);
	}
	else
	{
		game->p_position_counter -= 1;
		game->move_counter++;
		ft_printf("Move number %d\n", game->move_counter);
		if (game->map[game->p_position_counter][game->p_position_length] == 'C')
			game->c_collected++;
		if (game->map[game->p_position_counter
				+ 1][game->p_position_length] == 'e')
			game->map[game->p_position_counter
				+ 1][game->p_position_length] = 'E';
		else
			game->map[game->p_position_counter
				+ 1][game->p_position_length] = '0';
		game->map[game->p_position_counter][game->p_position_length] = 'P';
	}
	return (0);
}
