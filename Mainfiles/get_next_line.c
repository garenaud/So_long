/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:43:32 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/05 23:43:32 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_length(int fd)
{
	char	buffer[0];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

int	ft_count_lines(int fd)
{
	int		linecount;
	char	buffer[0];
	int		bytes;

	buffer[0] = '\0';
	linecount = 1;
	while (1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes < 1)
			break ;
		if (buffer[0] == '\n')
			linecount++;
	}
	return (linecount);
}

static size_t	ft_strlen_for_strdup(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen_for_strdup(str) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// char	*get_next_line(int fd)
// {
// 	char	buffer;
// 	char	*str_line;
// 	char	*tmp;
// 	int		i;

// 	if (fd < 0)
// 		return (NULL);
// 	i = 0;
// 	str_line = ft_strdup("");
// 	while (read(fd, &buffer, 1) > 0)
// 	{
// 		printf("buff %c\n", buffer);
// 		//str_line = ft_strjoin(str_line, buffer);
// 		tmp = str_line;
// 		if (buffer == '\n')
// 		{
// 			str_line = ft_strjoin(str_line, '\0');
// 			break ;
// 		}
// 		free (tmp);
// 	}
// 	i = ft_strlen(str_line);
// 	printf("i = %d", i);
// 	if (i == 0)
// 	{
// 		free(str_line);
// 		str_line = NULL;
// 	}
// 	return (str_line);
// }

static int	gnl_read(char **buff_s, char **line, int fd, int bli)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	ft_strdupcat(line, *buff_s);
	while (ft_strichr(*line, '\n') == -1)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret <= 0)
		{
			ft_strdel(buff_s);
			return (*line && (*line[0] != '\0'));
		}
		buff[ret] = '\0';
		ft_strdupcat(line, buff);
	}
	bli = ft_strichr(*line, '\n');
	if (bli >= 0)
	{
		ft_strdel(buff_s);
		ft_strdupcat(buff_s, &(*line)[bli + 1]);
		(*line)[bli + 1] = '\0';
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*data[FOPEN_MAX];
	char		*line;

	line = NULL;
	if (fd < FOPEN_MAX && fd >= 0 && !gnl_read(&(data[fd]), &line, fd, 0))
		ft_strdel(&line);
	return (line);
}

void	ft_strdel(char **str)
{
	if (str == NULL || *str == NULL)
	{
		return ;
	}
	else
	{
		free (*str);
		*str = NULL;
	}
}

char	*ft_strdupcat(char **s1, char *s2)
{
	char	*strnew;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!(*s1) && !s2)
		return (NULL);
	strnew = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2)) + 1);
	if (!strnew)
		return (NULL);
	while (*s1 && (*s1)[i])
		strnew[j++] = (*s1)[i++];
	i = 0;
	while (s2 && s2[i])
		strnew[j++] = s2[i++];
	strnew[j] = '\0';
	ft_strdel(s1);
	(*s1) = strnew;
	return (strnew);
}

int	ft_strichr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *) s) - 1;
	if (!s)
		return (NULL);
	if (!c || c == '\0')
		return ((char *)s + (i + 1));
	while (i >= 0)
	{
		if ((char) s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}