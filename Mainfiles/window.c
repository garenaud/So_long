/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:54:22 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/26 16:38:50 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_game *game, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message(RED"Error\nNo files found\n"ENDC, game);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		message(RED"Error\nyou need a .ber extension\n"ENDC, game);
	game->size_x = (ft_line_length(fd) * 48);
	game->size_y = (ft_count_lines(fd) * 48);
}

int	destroy_window(t_game *game)
{
	ft_printf(BOLDRED"You ended the game\n"ENDC, game);
	free_and_exit(game);
	exit (0);
}

void	free_and_exit(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->image.char_down.mlx_img);
	mlx_destroy_image(game->mlx, game->image.background.mlx_img);
	mlx_destroy_image(game->mlx, game->image.char_left.mlx_img);
	mlx_destroy_image(game->mlx, game->image.char_right.mlx_img);
	mlx_destroy_image(game->mlx, game->image.char_up.mlx_img);
	mlx_destroy_image(game->mlx, game->image.exit.mlx_img);
	mlx_destroy_image(game->mlx, game->image.coin.mlx_img);
	mlx_destroy_image(game->mlx, game->image.wall.mlx_img);
	mlx_destroy_window(game->mlx, game->window);
	while (i < ((game->size_y / 48) + 1))
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(0);
}
