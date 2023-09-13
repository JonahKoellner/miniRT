# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 09:27:00 by jkollner          #+#    #+#              #
#    Updated: 2023/09/13 09:44:38 by jkollner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================== Project =======================#
NAME = miniRT

#=================== Compile =======================#
CC = cc
CFLAGS = -Wall -Wextra -Werror

#=================== Library =======================#
MLXDIR = src/MLX42
MLXLIB = ${MLXDIR}/build/libmlx42.a
INCLUDE = ${MLXLIB} -Iinclude -lglfw -L"Users/$(USER)/homebrew/opt/glfw/lib/"

#=================== Files =======================#
SRC =


#=================== Commands =======================#
all: libmlx $(NAME)

libmlx:
	$(MAKE) -C $(MLXDIR)/build

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "\e[33mCompiling: $(notdir $<)\n"

$(NAME): $(SRC)
	@$(CC) $(SRC) $(MLXLIB) $(INCLUDE) -o $(NAME)

clean:
	@rm ${COBJS} && printf "\e[1;31m⚠️  Removed $(COBJS) ⚠️\e[0m\n"

fclean: clean
	@rm ${NAME} && printf "\e[1;31m⚠️  Removed $(NAME) ⚠️\e[0m\n"

re:		fclean all

.PHONY:	all clean fclean re
