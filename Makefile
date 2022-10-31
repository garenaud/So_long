# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grenaud- <grenaud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:06:39 by grenaud-          #+#    #+#              #
#    Updated: 2022/10/28 17:55:00 by grenaud-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -o so_long -framework OpenGL -framework AppKit -L./minilibx -lmlx 
DANGER = $(FLAGS) -g #-fsanitize=address
RMFOR1337 = rm -rf a.out
RM = @rm -rf

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = $(shell find . -name "*.c")
OBJECTS = $(CFILES:.c=.o)

all:
	@echo $(B)[Compilation start...]$(B)
	$(CC) ./mainfiles/*.c ./mainfiles/ft_printf/*.c $(DANGER)
	make -C ./mainfiles
	@echo $(G)[Compilation succsessful...]$(G)

clean:
	$(RM) ./mainfiles/*.o ./mainfiles/mainfiles
	$(RM) ./mainfiles/ft_printf/*.o
	$(RM) ./minilibx/*.o
	@echo $(R)Removed [./mainfiles/*.o]$(X)
	@echo $(R)Removed [./mainfiles/ft_printf/*.o]$(X)
	@echo $(R)Removed [./minilibx/*.o]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)

fclean:
	$(RM)  so_long so_long.dSYM
	$(RM) ./mainfiles/*.o ./mainfiles/mainfiles
	$(RM) ./mainfiles/ft_printf/*.o
	$(RM) ./minilibx/*.o
	@echo $(B)Removed [TEMPORARY FILES]$(X)
	@echo $(R)Removed [./mainfiles/*.o]$(X)
	@echo $(R)Removed [./mainfiles/ft_printf/*.o]$(X)
	@echo $(R)Removed [./minilibx/*.o]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)
	@echo $(R)Removed [REMOVED FINISH]$(X)

%.o: %.c
	$(CC) -g3 -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

norm:
	@echo $(G)[--NORMINETTE SUCCES %100 CLEAN CODE...]$(G)
	norminette $(shell find ./mainfiles/ -name "*.c")

build:
	docker build -t arch .
	docker run -ti -v /Users/grenaud-/so_long:/files arch

re: fclean all

.PHONY: re norm fclean clean all 