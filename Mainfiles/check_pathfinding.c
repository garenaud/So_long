/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathfinding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:23:05 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/24 22:14:06 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	get_cord(char **map, t_player object_cord)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	i = 0;
	while (map[i] && check != 1)
	{
		j = 0;
		while (map[i][j] && check != 1)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				map[i][j] = 'X';
				object_cord.y = i;
				object_cord.x = j;
				check = 1;
			}
			j++;
		}
		i++;
	}
	return (object_cord);
}

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

int	player_access(int x, int y, char **map, t_game *game)
{
	char		**copy;

	copy = copy_map(map, game);
	if (game->p_x == x && game->p_y == y)
		return (free_map(copy));
	copy[y][x] = '1';
	if (map[y][x - 1] != '1')
		if (player_access(x - 1, y, copy, game))
			return (free_map(copy));
	if (map[y - 1][x] != '1')
		if (player_access(x, y - 1, copy, game))
			return (free_map(copy));
	if (map[y][x + 1] != '1')
		if (player_access(x + 1, y, copy, game))
			return (free_map(copy));
	if (map[y + 1][x] != '1')
		if (player_access(x, y + 1, copy, game))
			return (free_map(copy));
	message(RED"Error\nSome objects are inaccessible \n"ENDC, game);
	return (free_map(copy) - 1);
}

void	check_access(t_game *game)
{
	t_player	object_cord;
	char		**map;
	int			max_cord;
	int			i;

	i = 0;
	game->p_x = game->player.x / 48;
	game->p_y = game->player.y / 48;
	printf("test (%d), (%d)\n", game->size_y, game->size_x);
	max_cord = game->coincheck + 1;
	map = copy_map(game->map, game);
	printf("fin de la copie\n\n\n\n");
	while (max_cord--)
	{
		object_cord = get_cord(map, object_cord);
		printf("coordonee = %i, %i\n\n\n", object_cord.x, object_cord.y);
		if (!player_access(object_cord.x, object_cord.y, map, game))
		{
			free_map(map);
			message(RED"Error\nSome objects are inaccessible \n"ENDC, game);
		}
	}
	free(map);
}
