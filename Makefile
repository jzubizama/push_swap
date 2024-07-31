NAME = push_swap
NAMECH = checker
LIBNAME = libft.a
SRC = ./src/push_swap.c  ./src/defined_func.c ./src/defined_func_2.c ./src/rot_quantity.c ./src/order.c ./src/check_arg.c ./src/list_func.c ./src/price.c ./src/split.c
SRCCH = ./bonus/checker_bonus.c ./src/defined_func.c ./src/defined_func_2.c ./src/order.c ./src/check_arg.c ./src/list_func.c ./src/split.c
#OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(LIBNAME)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(SRC) $(LINKS) $(LIBNAME) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(LIBNAME):
	@echo $(CURSIVE)$(GRAY) "     - Compiling LIBFT $(LIBNAME)..." $(NONE)
	@$(MAKE) -C ./libft all
	@cp ./libft/libft.a $(LIBNAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

#$(OBJ): $(SRC)
#	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
#	@gcc $(FLAGS) -c $< -o $@
bonus: $(NAME) $(LIBNAME)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAMECH)..." $(NONE)
	@gcc $(FLAGS) $(SRCCH) $(LINKS) $(LIBNAME) -o $(NAMECH)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@$(MAKE) -C ./libft clean
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME) And $(LIBNAME)..." $(NONE)
	@$(MAKE) -C ./libft fclean
	@rm -rf $(NAME) $(LIBNAME)

re: fclean all