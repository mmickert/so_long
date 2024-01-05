/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:07:18 by mickert           #+#    #+#             */
/*   Updated: 2024/01/05 18:09:02 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../suorce/libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct
{
	char	**map;
	int		fd;
	int		line_length;
	int		line_counter;
	int		flag;
	int		P;
	int		C;
	int		E;
	int		P_position_length;
	int		P_position_counter;
	int		C_counter;
	int		E_reachable;
	void	*minilib;
	void	*window;
	void	*island;
	void	*fish;
	void	*ocean;
	void	*rocket;
	void	*dolphin;

}	t_so_long;

int		main(int argc, char **argv);
void	parse(char **argv, t_so_long *game);
int		check_map_shape(t_so_long *game);
int		fill_map(t_so_long *game);
int		allocate_map(t_so_long *game, char **argv);
int		check_map_components(t_so_long *game);
int		is_allowed_char(char c);
void	check_map_walls(t_so_long *game);
void	error(t_so_long *game, int flag);
void	check_PEC(t_so_long *game);
void	positions_PEC(t_so_long *game, int i, int y);
void	flood_fill(t_so_long *game);
int		flood_fill_recursive(t_so_long *game, int start_length, int start_counter,
		int filled[][game->line_counter]);
void 	minilib(t_so_long *game);
void	fill_graphics(t_so_long *game);
void	fill_window(t_so_long *game);
void		set_map_to_PEC(t_so_long *game, int x, int y);

#endif