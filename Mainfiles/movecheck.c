/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:44:19 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/26 16:18:50 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_game *game, char **map, int x, int y)
{
	int	flag;

	if (x < 0 || (game->size_x / 48) < x || y < 0
		|| (game->size_y / 48) < y || map[y][x] == '1')
		return (0);
	if (map[y][x] == 'P')
		return (1);
	map[y][x] = 'X';
	flag = up(game, map, x, y);
	if (flag == 1)
		return (1);
	flag = down(game, map, x, y);
	if (flag == 1)
		return (1);
	flag = left(game, map, x, y);
	if (flag == 1)
		return (1);
	flag = right(game, map, x, y);
	if (flag == 1)
		return (1);
	return (0);
}

int	up(t_game *game, char **map, int x, int y)
{
	int	nx;
	int	ny;
	int	flag;

	nx = x;
	ny = y - 1;
	if (ny >= 0 && map[ny][nx] != '1' && map[ny][nx] != 'X')
	{
		flag = move(game, map, nx, ny);
		if (flag == 1)
			return (1);
	}
	return (0);
}

int	down(t_game *game, char **map, int x, int y)
{
	int	nx;
	int	ny;
	int	flag;

	nx = x;
	ny = y + 1;
	if (ny <= (game->size_y / 48) && map[ny][nx] != '1' && map[ny][nx] != 'X')
	{
		flag = move(game, map, nx, ny);
		if (flag == 1)
			return (1);
	}
	return (0);
}

int	left(t_game *game, char **map, int x, int y)
{
	int	nx;
	int	ny;
	int	flag;

	nx = x - 1;
	ny = y;
	if (nx >= 0 && map[ny][nx] != '1' && map[ny][nx] != 'X')
	{
		flag = move(game, map, nx, ny);
		if (flag == 1)
			return (1);
	}
	return (0);
}

int	right(t_game *game, char **map, int x, int y)
{
	int	nx;
	int	ny;
	int	flag;

	nx = x + 1;
	ny = y;
	if (nx <= (game->size_x / 48) && map[ny][nx] != '1' && map[ny][nx] != 'X')
	{
		flag = move(game, map, nx, ny);
		if (flag == 1)
			return (1);
	}
	return (0);
}
