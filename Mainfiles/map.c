/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:44:13 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/05 23:44:13 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (i < ((game.size_y / SIZE)))
	{
		j = 0;
		while (j < (game.size_x / SIZE))
		{
			if (game.map[i][j] == '1')
				mlx_put_image_to_window(game.mlx, game.window,
					game.image.wall.mlx_img, j * SIZE, i * SIZE);
			if (game.map[i][j] == 'P')
				mlx_put_image_to_window(game.mlx, game.window,
					game.image.char_down.mlx_img, j * SIZE, i * SIZE);
			if (game.map[i][j] == 'C')
				mlx_put_image_to_window(game.mlx, game.window,
					game.image.coin.mlx_img, j * SIZE, i * SIZE);
			if (game.map[i][j] == 'E')
				mlx_put_image_to_window(game.mlx, game.window,
					game.image.exit.mlx_img, j * SIZE, i * SIZE);
			j++;
		}
	i++;
	}
}

void	create_floor(t_game *game)
{
	int		j;
	int		i;

	i = 0;
	while (i <= game->size_y / SIZE)
	{
		j = 0;
		while (j < (game->size_x / SIZE))
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->image.background.mlx_img, j * 48, i * 48);
			j++;
		}
		i++;
	}
}

void	create_map_line(t_game *game, char **argv)
{
	int		fd;
	int		i;
	int		j;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	j = 0;
	game->map = malloc(sizeof(char *) * ((game->size_y / SIZE) + 1));
	while (i < (game->size_y / SIZE) + 1)
	{
		game->map[i] = get_next_line(fd);
		while (j < (game->size_x / SIZE) + 1)
		{
			check_map_endline(game, i, j);
			j++;
		}
		i++;
	}
	create_floor(game);
	create_map(*game);
	close(fd);
}

void	check_map_endline(t_game *game, int i, int j)
{
	if (game->map[i] == NULL)
	{
		ft_printf(RED"Error\nEmpty map\n"ENDC, game);
		exit(0);
	}
	if (game->map[i][j] == '\n')
		game->map[i][j] = '\0';
}
