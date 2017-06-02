NAME    = ft_ls

FILES   = main.c

SRCS    = $(addprefix src/, $(FILES))

OBJS    = $(SRCS:src/%.c=.obj/%.o)

INC     = -I includes -I libft/includes

FLAGS   = -Wall -Wextra -Werror

LIB     = -L libft -lft

CC      = gcc

all: $(NAME)

$(NAME): $(OBJS)

$(NAME):
	@echo "by 😉seng"
	@echo "\033[92m              __________________________________________________"
	@echo "\033[92m       	    /                                                    \'"
	@echo "\033[92m           |    _____________________________________________     |"
	@echo "\033[92m           |   |  __                                         |    |"
	@echo "\033[92m           |   | |  |		                             |    |"
	@echo "\033[92m           |   | |  |        ______                          |    |"
	@echo "\033[92m           |   | |  |       /  ___/                          |    |"
	@echo "\033[92m           |   | |  |___    \___  \                          |    |"
	@echo "\033[92m           |   | |_______\  /_____/                          |    |"
	@echo "\033[92m           |   |                                             |    |"
	@echo "\033[92m           |   |                                             |    |"
	@echo "\033[92m           |   |                                             |    |"
	@echo "\033[92m           |   |                                             |    |"
	@echo "\033[92m           |   |_____________________________________________|    |"
	@echo "\033[92m           |                                                      |"
	@echo "\033[92m            \_____________________________________________________/"
	@echo "\033[92m                   \_______________________________________/"
	@echo "\033[91mCompiling 🌮\033[97m"
	        @make -C libft
	        @$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	        @echo "\033[90m🍒Done\033[97m"
.obj/%.o: src/%.c
	mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)

clean:
	@echo "\033[92m🍺Deleting\033[97m"
	@rm -rf .obj
	@make clean -C libft
	@echo "\033[96m🍭Clean done\033[97m"

fclean: clean
	@echo "\033[92m🍺Deleting\033[97m"
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[96m🍺Fclean Done\033[97m"

re: fclean all

.PHONY: all clean fclean re
