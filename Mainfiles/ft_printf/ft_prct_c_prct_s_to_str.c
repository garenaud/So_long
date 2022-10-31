/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_c_prct_s_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:44:27 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/20 12:44:29 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_prct_c_prct_to_str(char *str, int idx, va_list ap)
{
	char	c;

	if (str[idx + 1] == 'c')
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		return (1);
	}
	else if (str[idx + 1] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_prct_s_to_str(char *str, int idx, va_list ap)
{
	char	*s;

	if (str[idx + 1] == 's')
	{
		s = va_arg(ap, char *);
		if (s == 0)
		{
			write(1, "(null)", 6);
			return (6);
		}
		else
			ft_putstr(s);
		return (ft_strlen(s));
	}
	return (0);
}
