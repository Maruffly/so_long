NAME		= so_long

CC 			= gcc -Wall -Wextra -Werror

INC = -I ./includes

SRCS		= ./src/main.c ./src/inputs_handler.c ./src/map_init.c \
				./src/map_parser.c ./src/map_print.c ./src/game_init.c \
				./src/map_accessibility.c ./src/free_destroy.c ./src/game_finish.c \
				./src/utils.c

LIBFT_LIB 	= ./libft/libft.a

LIBFT 		= ./libft/

LIBFT_FLAGS = -L$(LIBFT) -lft

MLX 		= ./mlx-linux

MLX_FLAGS	= -L$(MLX) -lmlx -lXext -lX11 -lm

OBJS		= $(SRCS:.c=.o)

${NAME}:		$(LIBFT_LIB) $(OBJS)
				@echo "$(CYAN)$(BOLD)$(NAME)$(RESET) $(GREEN)creating...$(RESET)"
				${CC} ${INC} ${OBJS} ${LIBFT_FLAGS} ${MLX_FLAGS} -o ${NAME}
				@echo "$(CYAN)$(BOLD)$(NAME):$(GREEN) created !$(RESET)"

%.o:%.c
		@$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

GREEN	= \033[0;32m
RED		= \033[0;31m
BOLD 	= \033[1m
CYAN 	= \033[36m
RESET	= \033[0m
