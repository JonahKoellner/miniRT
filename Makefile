# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 09:27:00 by jkollner          #+#    #+#              #
#    Updated: 2023/10/24 23:46:50 by mreidenb         ###   ########.fr        #
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

#LIBS = ${MLX} -Iinclude -lglfw -L"/Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib"
  LIBS = ${MLX} -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib"
INCLUDE = $(HEADER_INC) $(MLX_INC)

#=================== Files =======================#
ALL_C = $(SRC) $(ELEMENTS) $(HIT) $(UTILS) $(RAY) $(VEC3) $(MAT4) $(PARSER) $(TEXTURE)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_DIR = src/
SRC_FILES = miniRT.c

ELEMENTS = $(addprefix $(ELEMENTS_DIR), $(ELEMENTS_FILES))
ELEMENTS_DIR = $(addprefix $(SRC_DIR), elements/)
ELEMENTS_FILES = sphere.c cylinder.c plane.c materials.c cone.c lights.c

HIT = $(addprefix $(HIT_DIR), $(HIT_FILES))
HIT_DIR = $(addprefix $(SRC_DIR), hit/)
HIT_FILES = hit.c

UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
UTILS_DIR = $(addprefix $(SRC_DIR), utils/)
UTILS_FILES = colors.c anti_aliasing.c math_utils.c init.c

RAY = $(addprefix $(RAY_DIR), $(RAY_FILES))
RAY_DIR = $(addprefix $(UTILS_DIR), ray/)
RAY_FILES = ray.c

VEC3 = $(addprefix $(VEC3_DIR), $(VEC3_FILES))
VEC3_DIR = $(addprefix $(UTILS_DIR), vec3/)
VEC3_FILES = vec3_doub_op.c vec3_math.c vec3_utils.c vec3_vec3_op.c vec3_random.c

MAT4 = $(addprefix $(MAT4_DIR), $(MAT4_FILES))
MAT4_DIR = $(addprefix $(UTILS_DIR), mat4/)
MAT4_FILES = mat4_rotation.c mat4_translation.c

PARSER = $(addprefix $(PARSER_DIR), $(PARSER_FILES))
PARSER_DIR = $(addprefix $(SRC_DIR), parser/)
PARSER_FILES = parser.c gnl.c gnl_utils.c parser_create_hit.c parser_create_obj.c parser_error.c parser_utils.c parser_creation_utils.c

TEXTURE = $(addprefix $(TEXTURE_DIR), $(TEXTURE_FILES))
TEXTURE_DIR = $(addprefix $(SRC_DIR), textures/)
TEXTURE_FILES = texture.c texture_utils.c

#=================== Objects =======================#

COBJ =  $(pathsubst %.c, %.o, $(ALL_C))

OBJ				= $(ALL_OBJ_DIR)$(ALL_OBJ)
OBJ_DIR			=	.obj/
ALL_OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(ALL_C))
ALL_OBJ_DIR		=	$(sort $(dir $(ALL_OBJ)))

#=================== Commands =======================#
all: libft libmlx $(NAME)

libft: $(LIBFT)

libmlx: $(MLX)

$(LIBFT):
	@git submodule update --init --recursive
	@make -C lib/libft all

$(MLX):
	@git submodule update --init --recursive
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(ALL_OBJ_DIR):
	@mkdir -p $(ALL_OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(LIBFT_INC) && printf "\e[33mCompiled: $(notdir $<)\n"

$(NAME): $(OBJ)
	@$(CC) $(ALL_C) -o $(NAME) $(LIBS) $(LIBFT) && printf "\e[35mLinking: $(COBJ) ==> $(NAME)\n"
	@printf "\e[36mCreated target: $(NAME)\e[0m\n"

clean:
	@rm -rf $(OBJ_DIR) && printf "\e[1;31m⚠️  Removed $(OBJ_DIR) ⚠️\e[0m\n"
	@make -C $(LIBFT_DIR) clean && printf "\e[1;31m⚠️  Removed $(LIBFT_DIR)/*.o files ⚠️\e[0m\n"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX_DIR)/build && printf "\e[1;31m⚠️  Removed $(MLX_DIR)/build ⚠️\e[0m\n"
	@rm -f ${NAME} && printf "\e[1;31m⚠️  Removed $(NAME) ⚠️\e[0m\n"

re:		fclean all

.PHONY:	all clean fclean re libmlx
