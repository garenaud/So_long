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
			if (!(ft_strchr("1PCE0", game->map[y][x])))
				message(RED"Error\nWrong format\n"ENDC, game);
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				message(RED"Error\nWrong format\n"ENDC, game);
			else if ((y == ((game->size_y / SIZE) - 1)
					|| x == ((game->size_x / 48) - 1))
				&& game->map[y][x] != '1')
				message(RED"Error\nWrong format\n"ENDC, game);
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
			init_item(game, i, j);
			j++;
		}
		i++;
	}
}

void	check_item(t_game *game)
{
	if (game->coincheck == 0)
		message(RED"Error\nNo coins on the map!\n"ENDC, game);
	if (game->exitcheck != 1)
		message(RED"Error\nYou have no exit or too many\n"ENDC, game);
	if (game->playercheck != 1)
		message(RED"Error\nYou can only play one character\n"ENDC, game);
}

void	init_item(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E')
		game->exitcheck++;
	if (game->map[i][j] == 'P')
	{
		game->player.x = j * SIZE;
		game->player.y = i * SIZE;
		game->playercheck++;
	}
	if (game->map[i][j] == 'C')
	{
		if (pathfinding(game, j, i) == 0)
			message(RED"Error\nSolution doesn't exist\n"ENDC, game);
		game->coincheck++;
	}
}
