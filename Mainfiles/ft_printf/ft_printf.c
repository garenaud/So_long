/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:45:01 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/26 16:05:08 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	prct(const char *str, va_list ap, size_t idx, int size)
{
	size = 0;
	if (str[idx + 1] == 'c' || str[idx + 1] == '%')
		size = size + ft_prct_c_prct_to_str((char *)str, idx, ap);
	else if (str[idx + 1] == 's')
		size = size + ft_prct_s_to_str((char *)str, idx, ap);
	else if (str[idx + 1] == 'd' || str[idx + 1] == 'i'
		|| str[idx + 1] == 'u')
		size = size + ft_prct_d_i_u_to_str((char *)str, idx, ap);
	else if (str[idx + 1] == 'x' || str[idx + 1] == 'X'
		|| str[idx + 1] == 'p')
		size = size + ft_prct_x_xmaj_p_to_str((char *)str, idx, ap);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	idx;
	int		size;
	int		i;

	idx = 0;
	i = 0;
	size = 0;
	va_start(ap, str);
	while (str[idx] != '\0')
	{
		if (str[idx] != '%')
		{	
			write(1, &str[idx], 1);
			i++;
		}
		else if (str[idx] == '%')
		{
			size = size + prct(str, ap, idx, size);
			str++;
		}
		idx++;
	}
	va_end(ap);
	return (size + i);
}
