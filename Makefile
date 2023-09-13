# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 09:27:00 by jkollner          #+#    #+#              #
#    Updated: 2023/09/13 12:08:31 by jkollner         ###   ########.fr        #
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
SRC = miniRT.c src/utils/ray/ray.c src/utils/vec3/vec3_doub_op.c src/utils/vec3/vec3_math.c src/utils/vec3/vec3_utils.c src/utils/vec3/vec3_vec3_op.c src/colors.c
COBJ = ${SRC:.c=.o}

#=================== Commands =======================#
all: libmlx $(NAME)

libmlx:
	@cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "\e[33mCompiled: $(notdir $<)\n"

$(NAME): $(COBJ)
	@$(CC) $(SRC) $(LIBS) $(HEADER) -o $(NAME) && printf "\e[35mLinking: $(COBJ) ==> $(NAME)\n"
	@printf "\e[36mCreated target: $(NAME)\e[0m\n"

clean:
	@rm -f ${COBJ} && printf "\e[1;31m⚠️  Removed $(COBJ) ⚠️\e[0m\n"

fclean: clean
	@rm -rf $(MLXDIR)/build && printf "\e[1;31m⚠️  Removed $(MLXDIR)/build ⚠️\e[0m\n"
	@rm -f ${NAME} && printf "\e[1;31m⚠️  Removed $(NAME) ⚠️\e[0m\n"

re:		fclean all

.PHONY:	all clean fclean re libmlx
