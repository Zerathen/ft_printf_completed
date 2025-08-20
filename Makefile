# **************************************************************************** #
#                              ft_printf Makefile                              #
# **************************************************************************** #

NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = .
CONV_DIR    = Conv_Files

SRCS        = $(SRC_DIR)/ft_printf.c \
              $(SRC_DIR)/ft_printf_utils.c \
              $(CONV_DIR)/ft_print_ptr.c \
              $(CONV_DIR)/ft_print_u.c \
              $(CONV_DIR)/ft_print_x.c

OBJS        = $(SRCS:.c=.o)

bonus: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Built $(NAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "Clean (including $(NAME))"

re: fclean all

.PHONY: all clean fclean re bonus

