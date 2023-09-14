# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 09:27:00 by jkollner          #+#    #+#              #
#    Updated: 2023/09/14 01:45:44 by mreidenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================== Project =======================#
NAME = miniRT

#=================== Compile =======================#
CC = cc
CFLAGS = -Wall -Wextra -Werror

#=================== Header ========================#

HEADER_INC = -I $(HEADER_DIR)
HEADER_DIR = include/
HEADER_FILES = miniRT.h

#=================== Librarys ======================#

MLX = $(MLX_DIR)$(MLX_LIB)
MLX_DIR = ./lib/MLX42
MLX_LIB = /build/libmlx42.a
MLX_INC = -I $(MLX_DIR)/include

LIBFT = $(LIBFT_DIR)$(LIBFT_LIB)
LIBFT_LIB = /libft.a
LIBFT_DIR = ./lib/libft
LIBFT_INC = -I $(LIBFT_DIR)

LIBS = ${MLX} -Iinclude -lglfw -L"/Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib"
INCLUDE = $(HEADER_INC) $(MLX_INC)

#=================== Files =======================#
ALL_C = $(SRC) $(ELEMENTS) $(UTILS) $(RAY) $(VEC3)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_DIR = src/
SRC_FILES = miniRT.c

ELEMENTS = $(addprefix $(ELEMENTS_DIR), $(ELEMENTS_FILES))
ELEMENTS_DIR = $(addprefix $(SRC_DIR), elements/)
ELEMENTS_FILES = sphere.c

UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
UTILS_DIR = $(addprefix $(SRC_DIR), utils/)
UTILS_FILES = colors.c

RAY = $(addprefix $(RAY_DIR), $(RAY_FILES))
RAY_DIR = $(addprefix $(UTILS_DIR), ray/)
RAY_FILES = ray.c

VEC3 = $(addprefix $(VEC3_DIR), $(VEC3_FILES))
VEC3_DIR = $(addprefix $(UTILS_DIR), vec3/)
VEC3_FILES = vec3_doub_op.c vec3_math.c vec3_utils.c vec3_vec3_op.c

#=================== Objects =======================#

COBJ =  $(pathsubst %.c, %.o, $(ALL_C))

#=================== Commands =======================#
all: libft libmlx $(NAME)

libft: $(LIBFT)

$(LIBFT):
	@git submodule update --init --recursive
	@make -C lib/libft

libmlx: $(MLX)

$(MLX):
	@git submodule update --init --recursive
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) && printf "\e[33mCompiled: $(notdir $<)\n"

$(NAME): $(COBJ)
	@$(CC) $(ALL_C) $(LIBS) -o $(NAME) && printf "\e[35mLinking: $(COBJ) ==> $(NAME)\n"
	@printf "\e[36mCreated target: $(NAME)\e[0m\n"

clean:
	@rm -f ${COBJ} && printf "\e[1;31m⚠️  Removed $(COBJ) ⚠️\e[0m\n"

fclean: clean
	@rm -rf $(MLX_DIR)/build && printf "\e[1;31m⚠️  Removed $(MLX_DIR)/build ⚠️\e[0m\n"
	@rm -f ${NAME} && printf "\e[1;31m⚠️  Removed $(NAME) ⚠️\e[0m\n"

re:		fclean all

.PHONY:	all clean fclean re libmlx
