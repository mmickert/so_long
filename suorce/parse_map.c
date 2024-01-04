/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:02:43 by mickert           #+#    #+#             */
/*   Updated: 2024/01/03 18:10:59 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_shape(t_so_long *game)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		game->line_length = i;
		line = get_next_line(game->fd);
		if (line == NULL)
			break ;
		i = 0;
		while (line[i])
			i++;
		if (i > 0 && line[i - 1] == '\n')
			i--;
		if (game->line_length == 0)
			game->line_length = i;
		free(line);
		if (game->line_length != i)
			error(game, 23);
	}
	return (close(game->fd), game->line_length);
}

int	allocate_map(t_so_long *game, char **argv)
{
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
	{
		ft_putstr_fd("Error\nInvalid file path.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->map = (char **)ft_calloc(game->line_length, sizeof(char *));
	if (game->map == NULL)
	{
		ft_putstr_fd("Error\nMemory allocation error.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->line_counter = fill_map(game);
	return (game->line_counter);
}

int	fill_map(t_so_long *game)
{
	char	*line;
	int		i;

	game->line_counter = 0;
	i = 0;
	while (1)
	{
		line = get_next_line(game->fd);
		if (line == NULL)
			break ;
		game->line_counter++;
		game->map[i] = ft_strdup(line);
		free(line);
		if (game->map[i] == NULL)
		{
			ft_putstr_fd("Error\nMemory allocation error.\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (game->line_counter);
}

void	check_map_walls(t_so_long *game)
{
	int	i;
	int	y;

	i = 0;
	while (game->map[0][i] == '1')
		i++;
	if (i != game->line_length)
		error(game, 22);
	i = 0;
	y = 0;
	while (y < game->line_counter)
	{
		if (game->map[y][i] != '1' || game->map[y][game->line_length
			- 1] != '1')
			error(game, 22);
		y++;
	}
	i = 0;
	while (game->map[game->line_counter - 1][i] == '1')
		i++;
	if (i != game->line_length)
		error(game, 22);
}

int	is_allowed_char(char c)
{
	return (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E' || (c >= 9
			&& c <= 13) || c == 32);
}

int	check_map_components(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!is_allowed_char(game->map[i][j]))
				error(game, 24);
			j++;
		}
		i++;
	}
	check_map_walls(game);
	check_PEC(game);
	return (0);
}
