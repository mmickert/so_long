/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:07:18 by mickert           #+#    #+#             */
/*   Updated: 2024/01/02 15:56:09 by mickert          ###   ########.fr       */
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
	char **map;
	int	fd;
	int	line_length;
	int	line_counter;

}	t_so_long;

int		main(int argc, char **argv);
void	parse(char **argv, t_so_long *game);
int		check_map_shape(t_so_long *game);
int		fill_map(t_so_long *game);
int		allocate_map(t_so_long *game, char **argv);
int		check_map_components(t_so_long *game);


#endif