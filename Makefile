#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matvivan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 14:54:09 by matvivan          #+#    #+#              #
#    Updated: 2020/01/26 18:15:27 by matvivan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC = main.c

MLX = -LminiLibX/ -lmlx -framework OpenGL -framework AppKit

LFT = -Llibft/ -lft

FLAG = -Wall -Wextra -Werror

all: lib $(NAME)

$(NAME): $(SRC)
	@echo " ... [$(^:.c=.o) created]"
	@gcc -c $^
	@echo " ... [$(NAME) created]"
	@gcc $(^:.c=.o) $(MLX) $(LFT) $(FLAG) -o $(NAME) -g
	@echo " ... [clean $(^:.c=.o)]"
	@rm -f $(SRC:.c=.o)

lib :
	@make -s -C miniLibX/
	@make -s -C libft/

clean:
	@echo " ... [miniLibX removed]"
	@make clean -s -C miniLibX/
	@echo " ... [LibFT removed]"
	@make fclean -s -C libft/
	@echo " ... [$(NAME) removed]"
	@rm -f $(NAME)

re: clean all