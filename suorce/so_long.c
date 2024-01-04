/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:07:02 by mickert           #+#    #+#             */
/*   Updated: 2024/01/03 19:34:48 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	game;

	game.E = 0;
	game.C = 0;
	game.P = 0;
	ft_memset(&game, 0, sizeof(t_so_long));
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid input. Too many or few arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	parse(argv, &game);
// ft_printf("reached C: %d, real C: %d", game.C_counter, game.C);
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
	flood_fill(game);
	// find_all_Cs(game);
}

void	error(t_so_long *game, int flag)
{
	int	i;

	i = 0;
	if (flag == 24)
		ft_putstr_fd("Error\nInvalid character found in the map.\n", 2);
	else if (flag == 23)
		ft_putstr_fd("Error\nMap is not rectangular.\n", 2);
	else if (flag == 22)
		ft_putstr_fd("Error\nMap not surrounded by walls.\n", 2);
	else if (flag == 21)
		ft_putstr_fd("Error\nInvalid Player/Exit count.\n", 2);
	else if (flag == 20)
		ft_putstr_fd("Error\nP cannot reach E.\n", 2);
	else if (flag == 19)
		ft_putstr_fd("Error\nC not reachable.\n", 2);
	while (i < game->line_counter && game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(EXIT_FAILURE);
}
