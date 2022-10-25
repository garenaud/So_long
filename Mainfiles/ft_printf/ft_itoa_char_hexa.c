/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_char_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:43:37 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/20 12:43:39 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	ft_itoa_char_hexa(int nbr)
{
	char	c;

	if (nbr == 0)
		c = '0';
	while (nbr > 0 && nbr <= 9)
	{
		c = (nbr % 10) + '0';
		nbr = nbr / 16;
	}
	return (c);
}