/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:43:56 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/05 23:43:56 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message(char *msg, t_game *game)
{
	(void)game;
	ft_printf("%s", msg);
	free_and_exit(game);
	exit(0);
}

int	deal_key(int key_code, t_game *game)
{
	move_down(key_code, game);
	move_up(key_code, game);
	move_left(key_code, game);
	move_right(key_code, game);
	escape(key_code, game);
	return (0);
}

void	start(t_game *game)
{
	game->coincheck = 0;
	game->exitcheck = 0;
	game->player.coin = 0;
	game->player.move = 0;
	game->playercheck = 0;
}

void	initialisation_image(t_game *game)
{
	game->image.background.mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./img/floor.xpm",
			&game->image.background.width, &game->image.background.height);
	game->image.char_down.mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./img/Monkey_down.xpm",
			&game->image.char_down.width, &game->image.char_down.height);
	game->image.char_up.mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./img/Monkey_up.xpm",
			&game->image.char_up.width, &game->image.char_up.height);
	game->image.char_left.mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./img/Monkey_left.xpm",
			&game->image.char_left.width, &game->image.char_left.height);
	game->image.char_right.mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./img/Monkey_right.xpm",
			&game->image.char_right.width, &game->image.char_right.height);
	game->image.wall.mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./img/Barrel.xpm",
			&game->image.wall.width, &game->image.wall.height);
	game->image.exit.mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./img/ExitClosed.xpm",
			&game->image.exit.width, &game->image.exit.height);
	game->image.coin.mlx_img = mlx_xpm_file_to_image(game->mlx,
			"./img/FlagCoin.xpm",
			&game->image.coin.width, &game->image.coin.height);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		message(RED"Error\nYou can only enter 2 arguments\n", &game);
	ft_window_size(&game, argv);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.size_x, game.size_y, "So_long");
	initialisation_image(&game);
	create_map_line(&game, argv);
	start(&game);
	map_control(&game);
	check_item(&game);
	wall_control(&game);
	mlx_key_hook(game.window, deal_key, &game);
	mlx_hook(game.window, 17, 1L << 0, destroy_window, &game);
	mlx_hook(game.window, 17, 1L << 17, destroy_window, &game);
	mlx_loop(game.mlx);
	exit(0);
}
