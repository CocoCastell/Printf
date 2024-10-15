# Variables

NAME =	libftprintf.a
CFLAGS = -Wall -Werror -Wextra -I includes
LIBFT = libft/
RM = rm -f
AR = ar
CC = cc
INC = includes/

SRCS_DIR = src/
OBJS_DIR = obj/

SRCS =  ft_types.c ft_printf.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Rules

all:	$(NAME)
	@mkdir -p $(OBJS_DIR)
	@echo "Biblioteca $(GREEN)$(NAME)$(DEF_COLOR) creada amb èxit."
	
$(LIBFT)libft.a:
	@make --no-print-directory -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)libft.a
	@cp libft/libft.a .
	@$(AR) -x libft.a
	@$(AR) -rcs $@ $^ *.o
	@rm -f *.o
	@rm libft.a

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c Makefile $(INC)libft.h $(INC)ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make clean --no-print-directory -C $(LIBFT)
	@echo "Fitxers\n$(RED)$(OBJS) $(BONUS_OBJS)$(DEF_COLOR)\neliminats amb èxit."
fclean:
	@$(RM) $(NAME)
	@$(RM) -r $(OBJS_DIR)
	@make fclean --no-print-directory -C $(LIBFT)
	@echo "Directori $(RED)$(NAME) $(OBJS_DIR) $(DEF_COLOR)eliminats amb èxit."
re:	clean all

.PHONY: all clean fclean re
