# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 09:27:00 by jkollner          #+#    #+#              #
#    Updated: 2023/09/13 10:28:01 by jkollner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================== Project =======================#
NAME = miniRT

#=================== Compile =======================#
CC = cc
CFLAGS = -Wall -Wextra -Werror

#=================== Library =======================#
MLXDIR = ./lib/MLX42
MLXLIB = ${MLXDIR}/build/libmlx42.a
HEADER = -I ./include -I $(MLXDIR)/include
LIBS = ${MLXLIB} -Iinclude -lglfw -L"/Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib"

#=================== Files =======================#
SRC = miniRT.c
COBJ = ${SRC:.c=.o}

#=================== Commands =======================#
all: libmlx $(NAME)
	@printf "\e[36mCreated target: $(NAME)\e[0m\n"

libmlx:
	@cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "\e[33mCompiling: $(notdir $<)\n"

$(NAME): $(COBJ)
	@$(CC) $(SRC) $(LIBS) $(HEADER) -o $(NAME) && printf "\e[35mLinking: $(notdir $<)\n"

clean:
	@rm -f ${COBJ} && printf "\e[1;31m⚠️  Removed $(COBJ) ⚠️\e[0m\n"
	@rm -rf $(MLXDIR)/build && printf "\e[1;31m⚠️  Removed $(MLXDIR)/build ⚠️\e[0m\n"

fclean: clean
	@rm -f ${NAME} && printf "\e[1;31m⚠️  Removed $(NAME) ⚠️\e[0m\n"

re:		fclean all

.PHONY:	all clean fclean re libmlx
