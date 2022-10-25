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
	j = 0;
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
		//game->map[i] = malloc(sizeof(char) * ((game->size_x / SIZE)));
		while (j < (game->size_x / SIZE) + 1)
		{
			if(game->map[i] == NULL)
				break;
			if (game->map[i][j] == '\n')
			{
				game->map[i][j] = '\0';
				break;
			}
			j++;
		}
		i++;
	}
//	game->map[i] = NULL;
	create_floor(game);
	create_map(*game);
	close(fd);
}

/* void	create_map_line(t_game *game, char **argv)
{
	int		fd;
	// char	*area;
	int		i;
	int		j;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	j = 0;
	game->map = malloc(sizeof(char *) * ((game->size_y / SIZE) + 1));
	while (i < (game->size_y / SIZE) + 1)
	{
		game->map[i] = malloc(sizeof(char) * ((game->size_x / SIZE) + 1));
		game->map[i] = get_next_line(fd);
		while (j < (game->size_x / SIZE))
		{
			if (game->map[i][j] == '\n')
			{
				game->map[i][j] = '\0';
				break;
			}
			j++;
		}
		//printf("maps[%i] = %s\n", i, game->map[i]);
		i++;
	}
	game->map[i][j] = NULL;
	create_floor(*game);
	create_map(game);
	//printf("i = %d\n", i);
	close(fd);
} */
