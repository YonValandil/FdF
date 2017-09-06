.PHONY: clean fclean re
.SUFFIXES:

CC =		gcc
EXEC =		fdf
LIB =		ft
SRCS_DIR =	./
OBJS_DIR =	./
LIB_DIR = 	./libft/
MLX = 		-lmlx -framework OpenGL -framework AppKit
HEADER =	./
CFLAGS =	-Wall -Werror -Wextra -g
ARFLAGS =	-rcs
CFILES =	main

SRCS =		$(CFILES:%=$(SRCS_DIR)%.c)
OBJS =		$(SRCS:%.c=$(OBJS_DIR)%.o)

all:
	make -C libft/
	$(CC) $(SRCS) -I$(HEADER) -Ilibft/ -L$(LIB_DIR) -l$(LIB) $(MLX) -o $(EXEC) $(CFLAGS)

clean:
	rm -f $(OBJS)
	@make libft/ clean
	@echo clean $@ Done !

fclean:		clean
	rm -f $(EXEC)
	@make libft/ fclean
	@echo fclean $@ Done !

re:			fclean all

##-Lminilibx_macos
