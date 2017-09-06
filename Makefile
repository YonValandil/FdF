.PHONY: clean fclean re
.SUFFIXES:

CC =		gcc
EXEC =		fdf
LIB =		ft
SRCS_DIR =	./
OBJS_DIR =	./
LIB_DIR = 	./
HEADER =	./
CFLAGS =	-Wall -Werror -Wextra -g
ARFLAGS =	-rcs
CFILES =	main

SRCS =		$(CFILES:%=$(SRCS_DIR)%.c)
OBJS =		$(SRCS:%.c=$(OBJS_DIR)%.o)

all:
	$(CC) $(SRCS) -I$(HEADER) -lmlx -framework OpenGL -framework AppKit -o $(EXEC) $(CFLAGS)

clean:
	rm -f $(OBJS)
	@echo clean $@ Done !

fclean:		clean
	rm -f $(EXEC)
	@echo fclean $@ Done !

re:			fclean all
