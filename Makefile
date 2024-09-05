# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkuyucu <hkuyucu@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 10:29:24 by hkuyucu           #+#    #+#              #
#    Updated: 2023/06/14 10:29:25 by hkuyucu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC	= cc -Wall -Wextra -Werror -g -O3

NAME	= fractol
SRC	= src/control.c\
	  src/draw.c\
	  src/main.c\
	  src/utils.c\

OBJ  = $(SRC:.c=.o)

all : $(NAME) 

CLR_RMV:= \033[0m
RED:= \033[1;31m
GREEN:= \033[1;32m
YELLOW:= \033[1;33m
BLUE:= \033[1;34m
CYAN:= \033[1;36m


$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(BLUE)Compilation of ${YELLOW}$(NAME) $(RED)BY Parametros ..."
	@echo "✔️"

%.o : %.c fractol.h
	@$(CC) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@echo "$(RED)$(NAME) $(GREEN)OBJS DELETED ✔️"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME) $(GREEN)DELETED ✔️"

re : fclean all
