/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:56:01 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/24 21:59:23 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(t_game *game)
{
	if (game->coincheck != 0)
	{
		ft_printf(RED"You missed %d coins\n", game->coincheck);
	}
	if (game->coincheck == 0)
	{
		message(GREEN"You won!\n"ENDC, game);
	}
	return (0);
}
