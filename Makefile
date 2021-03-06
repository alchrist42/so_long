NAME		=	so_long
NAME_B		=	so_long_bonus

SRCS_FILES	= 	so_long.c \
				parcer.c \
				parcer_check_map.c \
				parcer_load_file.c \
				game.c \
				draws.c \
				hookes.c \
				load_resurses.c \
				moves.c \
				raise_error.c \
				gnl/get_next_line.c \

SRCS_B_F	= 	so_long.c \
				parcer.c \
				parcer_check_map.c \
				parcer_load_file.c \
				game.c \
				draws.c \
				hookes.c \
				load_resurses.c \
				moves.c \
				animations.c \
				raise_error.c \
				gnl/get_next_line.c \

SRCS_FOLDER	=	source/
SRCS_B_FLD	=	source_bonus/

SRCS		= 	$(addprefix $(SRCS_FOLDER),$(SRCS_FILES))
SRCS_B		=	$(addprefix $(SRCS_B_FLD),$(SRCS_B_F))
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))

INCLUDE		=	-I./include -I./source/libft/ -I./source/gnl/ -I./source/mlx/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -MMD
FRAMEWORK	=	-framework OpenGL -framework AppKit
RM			=	rm -rf


MLX = ./source/mlx/libmlx.a
LIB = ./source/libft/libft.a

all:		$(NAME)

bonus:		$(NAME_B)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c -g $< -o $@
		
$(NAME):	$(OBJS)
			$(MAKE) -C $(dir $(MLX)) 2> /dev/null
			$(MAKE) -C $(dir $(LIB))
			$(CC) $(INCLUDE) $(FRAMEWORK) $(MLX) $(LIB) -o $(NAME) $(OBJS)

$(NAME_B):	$(OBJS_B)
			$(MAKE) -C $(dir $(MLX)) 2> /dev/null
			$(MAKE) -C $(dir $(LIB))
			$(CC) $(INCLUDE) $(FRAMEWORK) $(MLX) $(LIB) -o $(NAME_B) $(OBJS_B)

clean:
			$(RM) $(OBJS) $(OBJS:.o=.d)
			# $(RM) $(OBJS_B) $(OBJS_B:.o=.d)
			@make -C $(dir $(MLX)) clean
			@make -C $(dir $(LIB)) clean

fclean:		clean
			@make -C $(dir $(LIB)) fclean
			$(RM) $(MLX)
			$(RM) $(NAME)
			# $(RM) $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean re bonus
-include	$(OBJS:.o=.d)
-include	$(OBJS_B:.o=.d)