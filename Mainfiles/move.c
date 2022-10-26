/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:44:23 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/05 23:44:23 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	escape(int key_code, t_game *game)
{
	if (key_code == ESC)
		destroy_window(game);
	return (0);
}

int	move_down(int key_code, t_game *game)
{
	if (key_code == DOWN || key_code == 125)
	{
		if (game->map[(game->player.y / 48) + 1][(game->player.x / 48)] == '1')
			return (0);
		if (game->map[(game->player.y / 48) + 1][(game->player.x / 48)] == 'C')
		{	
			game->coincheck--;
			game->map[(game->player.y / 48) + 1][(game->player.x / 48)] = '0';
		}
		if (game->map[(game->player.y / 48) + 1][(game->player.x / 48)] == 'E')
		{
			check_exit(game);
			return (0);
		}
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.background.mlx_img, game->player.x, game->player.y);
		game->player.y += 48;
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.char_down.mlx_img, game->player.x, game->player.y);
		game->player.move++;
		ft_printf(GREEN"number of move: %d\n"ENDC, game->player.move);
	}
	return (0);
}

int	move_right(int key_code, t_game *game)
{
	if (key_code == RIGHT || key_code == 124)
	{
		if (game->map[(game->player.y / 48)][(game->player.x / 48) + 1] == '1')
			return (0);
		if (game->map[(game->player.y / 48)][(game->player.x / 48) + 1] == 'C')
		{	
			game->coincheck--;
			game->map[(game->player.y / 48)][(game->player.x / 48) + 1] = '0';
		}
		if (game->map[(game->player.y / 48)][(game->player.x / 48) + 1] == 'E')
		{
			check_exit(game);
			return (0);
		}
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.background.mlx_img, game->player.x, game->player.y);
		game->player.x += 48;
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.char_left.mlx_img, game->player.x, game->player.y);
		game->player.move++;
		ft_printf(GREEN"number of move: %d\n"ENDC, game->player.move);
	}
	return (0);
}

int	move_up(int key_code, t_game *game)
{
	if (key_code == UP || key_code == 126)
	{
		if (game->map[(game->player.y / 48) - 1][(game->player.x / 48)] == '1')
			return (0);
		if (game->map[(game->player.y / 48) - 1][(game->player.x / 48)] == 'C')
		{	
			game->coincheck--;
			game->map[(game->player.y / 48) - 1][(game->player.x / 48)] = '0';
		}
		if (game->map[(game->player.y / 48) - 1][(game->player.x / 48)] == 'E')
		{
			check_exit(game);
			return (0);
		}
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.background.mlx_img, game->player.x, game->player.y);
		game->player.y -= 48;
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.char_up.mlx_img, game->player.x, game->player.y);
		game->player.move++;
		ft_printf(GREEN"number of move: %d\n"ENDC, game->player.move);
	}
	return (0);
}

int	move_left(int key_code, t_game *game)
{
	if (key_code == LEFT || key_code == 123)
	{
		if (game->map[(game->player.y / 48)][(game->player.x / 48) - 1] == '1')
			return (0);
		if (game->map[(game->player.y / 48)][(game->player.x / 48) - 1] == 'C')
		{	
			game->coincheck--;
			game->map[(game->player.y / 48)][(game->player.x / 48) - 1] = '0';
		}
		if (game->map[(game->player.y / 48)][(game->player.x / 48) - 1] == 'E')
		{
			check_exit(game);
			return (0);
		}
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.background.mlx_img, game->player.x, game->player.y);
		game->player.x -= 48;
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.char_right.mlx_img, game->player.x, game->player.y);
		game->player.move++;
		ft_printf(GREEN"number of move: %d\n"ENDC, game->player.move);
	}
	return (0);
}
