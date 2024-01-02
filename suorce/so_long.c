/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:07:02 by mickert           #+#    #+#             */
/*   Updated: 2024/01/02 16:12:48 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	game;

	ft_memset(&game, 0, sizeof(t_so_long));
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid input. Too many or few arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	parse(argv, &game);
	return (0);
}

// system("leaks so_long");

void	parse(char **argv, t_so_long *game)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (ft_strnstr(argv[1], ".ber", i) == NULL)
	{
		ft_putstr_fd("Error\nInput needs to be a .ber file.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
	{
		ft_putstr_fd("Error\nInvalid file path.'\n", 2);
		exit(EXIT_FAILURE);
	}
	check_map_shape(game);
	game->line_counter = allocate_map(game, argv);
	check_map_components(game);
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
			{
				ft_printf("Error\nInvalid character found in the map.\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
ft_printf("linelength: %d\n", game->line_length);
ft_printf("linecount: %d\n", game->line_counter);
	return (0);
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
		if (game->line_length != i
			&& (ft_putstr_fd("Error\nMap is not rectangular.\n", 2), 1))
			exit(1);
	}
	return (close(game->fd), game->line_length);
}

/*next steps:
- are the walls all 1s? (using line count and length)
- are there only one E and P?
- how many Cs?
- floodfill - erf - can p reach e?
- are all the Cs reachable? (how many cs can p reach, is that the same as c number?)
*/