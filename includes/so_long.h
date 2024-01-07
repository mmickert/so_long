/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:07:18 by mickert           #+#    #+#             */
/*   Updated: 2024/01/06 18:06:42 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../suorce/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_so_long
{
	char	**map;
	int		fd;
	int		line_length;
	int		line_counter;
	int		flag;
	int		p;
	int		c;
	int		e;
	int		p_position_length;
	int		p_position_counter;
	int		c_counter;
	int		c_collected;
	int		e_reachable;
	void	*minilib;
	void	*window;
	void	*island;
	void	*fish;
	void	*ocean;
	void	*rocket;
	void	*dolphin;
	int		move_counter;

}			t_so_long;

int			main(int argc, char **argv);
void		parse(char **argv, t_so_long *game);
int			check_map_shape(t_so_long *game);
int			fill_map(t_so_long *game);
int			allocate_map(t_so_long *game, char **argv);
int			check_map_components(t_so_long *game);
int			is_allowed_char(char c);
void		check_map_walls(t_so_long *game);
void		error(t_so_long *game, int flag);
void		check_pec(t_so_long *game);
void		positions_pec(t_so_long *game, int i, int y);
void		flood_fill(t_so_long *game);
int			flood_fill_recursive(t_so_long *game, int start_length,
				int start_counter, int filled[][game->line_counter]);
void		minilib(t_so_long *game);
void		fill_graphics(t_so_long *game);
void		fill_window(t_so_long *game);
void		set_map_to_pec(t_so_long *game, int x, int y);
int			key_press(int key_pressed, t_so_long *game);
void		check_e(t_so_long *game);
int			key_w(t_so_long *game, int temp_pos);
int			key_s(t_so_long *game, int temp_pos);
int			key_a(t_so_long *game, int temp_pos);
int			key_d(t_so_long *game, int temp_pos);
void		clean_exit(t_so_long *game);
void		check_e_aswd(t_so_long *game);

#endif