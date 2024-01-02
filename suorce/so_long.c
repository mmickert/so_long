/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:07:02 by mickert           #+#    #+#             */
/*   Updated: 2024/01/02 11:22:37 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	game;

	ft_memset(&game, '\0', sizeof(t_so_long));
	if (argc != 2)
	{
		ft_putstr_fd("Invalid input. Too many or few arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	parse(argv, &game);
	return (0);
}

//system("leaks so_long");

void	parse(char **argv, t_so_long *game)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (ft_strnstr(argv[1], ".ber", i) == NULL)
	{
		ft_putstr_fd("Input needs to be a .ber file.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
	{
		ft_putstr_fd("Invalid file path.'\n", 2);
		exit(EXIT_FAILURE);
	}
	parse_map_shape(game);
	// parse_map_components(game);
}

// int	parse_map_components(t_so_long *game)
// {
// 	game->map = game->fd;
// 	return 0;
// }

int	parse_map_shape(t_so_long *game)
{
	int		i;
	int		y;
	char	*line;

	i = 0;
	while (1)
	{
		y = i;
		line = get_next_line(game->fd);
		if (line == NULL)
			break;
		i = 0;
		while (line[i])
			i++;
		if (y == 0)
			y = i;
		free(line);
		if (y != i)
		{
			ft_putstr_fd("Map is not rectangular.\n", 2);
			exit(1);
		}
	}
	return (0);
}
