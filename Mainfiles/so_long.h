/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:44:36 by grenaud-          #+#    #+#             */
/*   Updated: 2022/10/05 23:44:36 by grenaud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define BOLDRED    "\033[31m"
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53
# define SIZE   48

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_player
{
	int		x;
	int		y;
	int		coin;
	int		move;
}			t_player;

typedef struct s_img
{
	void	*mlx_img;
	int		height;
	int		width;
}	t_img;

typedef struct s_image
{
	t_img	char_down;
	t_img	char_left;
	t_img	char_right;
	t_img	char_up;
	t_img	wall;
	t_img	coin;
	t_img	exit;
	t_img	background;
}			t_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			p_x;
	int			p_y;
	int			img_size;
	int			coincheck;
	int			playercheck;
	int			exitcheck;
	int			size_x;
	int			size_y;
	t_player	player;
	t_image		image;
}				t_game;

size_t		ft_strlen(const char *str);

//int		key_check(int key_code, t_game *game);
int		destroy_window(t_game *game);
int		ft_line_length(int fd);
int		ft_count_lines(int fd);

void	start(t_game *game);
void	message(char *msg, t_game *game);
void	wall_control(t_game *game);
void	map_control(t_game *game);
void	game_control(t_game *game);
int		move_check(t_game *game, int i, int j);
void	ft_window_size(t_game *data, char **argv);
void	create_map(t_game game);
void	create_floor(t_game *game);
void	create_map_length(char *area, t_game *game, int i);
void	create_map_line(t_game *game, char **argv);
/* void	update(t_game *game, int x, int y);
void	right(t_game *game);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game); */
void	map_destroy(t_game	*game);
void	initialisation_image(t_game *game);

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s, char c);
char	*ft_strdup(const char *str);
//static size_t	ft_strlen_for_strdup(const char *str);

int		ft_printf(const char *str, ...);
int		ft_dec_to_hexa(unsigned int nb);
int		ft_dec_to_hexa_maj(unsigned int nb);
int		ft_dec_to_hexa_p(unsigned long long int nb);
size_t	ft_nbrlen(int nb);
size_t	ft_nbrlen_plus(unsigned int nb);
size_t	ft_nbrlen_hexa(unsigned int nb);
size_t	ft_nbrlen_hexa_p(unsigned long long int nb);
char	ft_itoa_char_hexa(int nbr);
int		ft_putptr(unsigned long long int nb);
int		ft_prct_c_prct_to_str(char *str, int idx, va_list ap);
int		ft_prct_s_to_str(char *str, int idx, va_list ap);
int		ft_prct_d_i_u_to_str(char *str, int idx, va_list ap);
int		ft_prct_x_xmaj_p_to_str(char *str, int idx, va_list ap);
void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

int		deal_key(int key_code, t_game *game);
int		move_left(int key_code, t_game *game);
int		move_up(int key_code, t_game *game);
int		move_right(int key_code, t_game *game);
int		move_down(int key_code, t_game *game);
int		escape(int key_code, t_game *game);

int		check_exit(t_game *game);

int		destroy_window2(t_game *game);
int		exit_game_esc(int key, t_game *game);
void	free_and_exit(t_game *game);

char		**copy_map(char **map, t_game *game);
//void		check_access(t_game *game);
//int			player_access(int x, int y, char **map, t_game *game);
int			free_map(char **map);
//t_player	get_cord(char **map, t_player object_cord);

int			pathfinding(t_game *game, int x, int y);
int			move(t_game *game, char **map, int x, int y);
int			up(t_game *game, char **map, int x, int y);
int			down(t_game *game, char **map, int x, int y);
int			left(t_game *game, char **map, int x, int y);
int			right(t_game *game, char **map, int x, int y);

char	*ft_strdupcat(char **s1, char *s2);
void	ft_strdel(char **str);
int		ft_strichr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

#endif
