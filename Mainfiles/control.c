/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:39:48 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/05 23:39:48 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_control(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (game->size_y / SIZE))
	{
		x = 0;
		while (x < (game->size_x / SIZE))
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				message(RED"Error\nWalls missing at the start"ENDC, game);
			else if ((y == (game->size_y / SIZE)
					|| x == (game->size_x / SIZE))
					&& game->map[y][x] != '1')
				message(RED"Walls missing at the end"ENDC, game);
			x++;
		}
		y++;
	}
}

void	map_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (game->size_y / SIZE))
	{
		j = 0;
		while (j < (game->size_x / SIZE))
		{
			if (game->map[i][j] == 'E')
				game->exitcheck++;
			j++;
		}
		i++;
	}
	if (game->coincheck == 0)
		message(RED"Error\nNo coins on the map!\n"ENDC, game);
	if (game->exitcheck != 1)
		message(RED"Error\nYou have no exit or too many\n"ENDC, game);
	if (game->playercheck != 1)
		message(RED"Error\nWhere is the player?\n"ENDC, game);
}

void	game_control(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (game->size_y / SIZE))
	{
		j = 0;
		while (j <= (game->size_x / SIZE))
		{
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * SIZE;
				game->player.y = i * SIZE;
				game->playercheck++;
			}
			if (game->map[i][j] == 'C')
				game->coincheck++;
			j++;
		}
		i++;
	}
	map_control(game);
	wall_control(game);
}

/* int	move_check(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'C')
	{
		game->player.coin++;
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coin != game->coincheck)
			ft_printf(RED"You missed some coins\n"ENDC);
		message(GREEN"You won!\n"ENDC, game);
		return (0);
	}
	return (0);
} */
