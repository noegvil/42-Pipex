NAME = pipex
LIBFT = libft/libft.a

CC = gcc 
CFLAGS = -Wall -Werror -Wextra
CLEAN = rm -f

SRC := \
	src/pipex.c \
	src/pathname.c \
	src/execute.c \
	src/first_command.c \
	src/second_command.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft
	
clean:
	$(CLEAN) $(OBJS)
	make clean -C ./libft

fclean: clean
	$(CLEAN) $(NAME)
	make fclean -C ./libft

re: fclean all
.PHONY: all clean fclean re bonus