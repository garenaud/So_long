/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathfinding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:23:05 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/25 19:47:11 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, t_game *game)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	new = malloc(sizeof(char *) * ((game->size_y / SIZE) + 1));
	while (i < ((game->size_y / SIZE)))
	{
		j = 0;
		new[i] = malloc(sizeof(char) * ((game->size_x / SIZE) + 1));
		while (j < ((game->size_x / SIZE)))
		{
			new[i][j] = map[i][j];
			j++;
		}
		new[i][j] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int	pathfinding(t_game *game, int x, int y)
{
	char	**map;

	map = copy_map(game->map, game);
	if (map == NULL)
		return (0);
	if (move(game, map, x, y) == 1)
	{
		free_map(map);
		return (1);
	}
	else
	{
		free_map(map);
		return (0);
	}
}
