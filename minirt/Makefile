NAME		=	miniRT

SRCS		=	main.c									close_program.c \
				rendering/render.c						rendering/cast_ray.c \
				rendering/utils/ambient.c				rendering/utils/math.c \
				rendering/utils/vector.c				rendering/utils/colors.c \
				rendering/utils/loader.c				rendering/utils/random.c \
				rendering/utils/coordinate_system.c		rendering/utils/vector_methods.c \
				rendering/utils/vector_operations.c		\
				\
				rendering/shapes/cone/cone.c			rendering/shapes/cone/cone_intersection.c \
				rendering/shapes/cylinder/cylinder.c	rendering/shapes/cylinder/cylinder_intersection.c \
				rendering/shapes/cone/cone_texture.c	rendering/shapes/cylinder/cylinder_texture.c \
				rendering/shapes/sphere.c				rendering/shapes/plane.c \
				rendering/shapes/circle.c				\
				\
				rendering/shading/shading.c				rendering/shading/direct_light_sampling.c \
				rendering/shading/texture.c \
				\
				rendering/events/hooks.c				rendering/events/mouse_events.c \
				rendering/events/key_events.c			\
				\
				parsing/normal_map/parse_normal_map.c	\
				parsing/normal_map/fill_good_maps.c	\
				parsing/parsing.c	\
				parsing/utils/error_message.c	parsing/utils/fonction_utils.c \
				parsing/input/get_content.c		parsing/input/check_input.c\
				parsing/input/check_argument.c\
				parsing/type/type_unique.c		parsing/type/type.c	\
				parsing/type/check_syntax/other.c parsing/type/check_syntax/range.c \
				parsing/type/check_syntax/rgb.c parsing/type/check_syntax/null.c\
				parsing/type/check_syntax/vector.c parsing/type/check_syntax/letter.c\
				parsing/type/type_cylinder_cone_optionnal.c \
				parsing/fill_rt/fill_rt.c parsing/fill_rt/fill_rt_utils.c\
				parsing/fill_rt/materials/fill_data.c	parsing/fill_rt/materials/fill_materials.c \
				parsing/fill_rt/get_number/conversion.c parsing/fill_rt/get_number/get_value.c\

OBJS_DIR	=	$(addprefix binaries/, ${SRCS})

OBJS		=	$(OBJS_DIR:%.c=%.o)

LIB			=	libft.a

LIBFT		=	Libft

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

INC_LIB		=	-ILibft/includes/libc -ILibft/includes/gnl -Iincludes

INCLUDES	=	-Imlx $(INC_LIB)
MINILIBX	=	mlx
XFLAGS	=	-lmlx -lXext -lX11

MATH_LIB	=	-lm

RM			=	rm -f

HEADERS		=	includes/minirt.h includes/parsing.h includes/rendering.h includes/structures.h

MAKEFLAGS	+=	--no-print-directory

all :  ${NAME} | libs

binaries/%.o : %.c Makefile $(HEADERS) | binaries
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -I./includes $(INCLUDES) -c $< -o $@

${NAME} : ${OBJS} | libs
	@${CC} ${OBJS} -LLibft -lft -Lmlx -lmlx -lX11 -lXext -lm -o ${NAME}
	@echo "\033[32mminiRT compiled"

mlx/libmlx.a:
	@$(MAKE) -C $(MINILIBX)
	@echo "\033[32mmililibx compiled"

Libft/libft.a:
	@$(MAKE) -C Libft

libs: mlx/libmlx.a Libft/libft.a

binaries:
		@mkdir -p binaries

bonus: all

clean:
		@$(RM) -r binaries/
		@$(MAKE) clean -C $(MINILIBX)
		@echo "\033[36mminilibx is clean"
		@$(MAKE) clean -C Libft
		@echo "\033[36mLibft is clean"
		@echo "\033[36mminiRT is clean"

fclean:	clean
		@$(RM) $(NAME)
		@$(MAKE) fclean -C Libft
		@echo "\033[36mminiRT file is delete"

re:		fclean all

.PHONY: all libs clean fclean re