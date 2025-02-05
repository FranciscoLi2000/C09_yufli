NAME = libft.a
SRC_DIR = srcs
INCLUDE_DIR = includes
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)
AR = ar
ARFLAGS = rcs

.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@echo "Removing object files..."
	@rm -f $(OBJ)
fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
re: fclean all
