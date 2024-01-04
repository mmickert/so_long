/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:07:18 by mickert           #+#    #+#             */
/*   Updated: 2024/01/04 11:58:58 by mickert          ###   ########.fr       */
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

#endif