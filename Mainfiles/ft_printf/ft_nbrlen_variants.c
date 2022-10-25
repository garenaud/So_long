/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_variants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:44:17 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/20 12:44:19 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_nbrlen(int nb)
{
	size_t	i;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		i = 1;
	else if (nb > 0)
		i = 0;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

size_t	ft_nbrlen_plus(unsigned int nb)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

size_t	ft_nbrlen_hexa(unsigned int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

size_t	ft_nbrlen_hexa_p(unsigned long long int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}
