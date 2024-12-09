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

SRCS = ft_types.c ft_printf.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

BONUS_DIR = bonus/
BONUS_OBJS_DIR = bonus/obj/
SRCS_BONUS = ft_manager_bonus.c ft_printf_bonus.c ft_types_bonus.c
OBJS_BONUS = $(addprefix $(BONUS_OBJS_DIR), $(SRCS_BONUS:.c=.o))

# Colors

DEF_COLOR = \033[0m
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
	@echo "Biblioteca $(MAGENTA)$(NAME)$(DEF_COLOR) creada amb èxit."

bonus: fclean $(OBJS_BONUS) $(LIBFT)libft.a 
	@cp libft/libft.a .
	@$(AR) -x libft.a
	@$(AR) -rcs $(NAME) $(OBJS_BONUS) *.o
	@rm -f *.o
	@rm libft.a
	@echo "Biblioteca $(MAGENTA)$(NAME)$(DEF_COLOR) creada amb èxit."

$(BONUS_OBJS_DIR)%.o: $(BONUS_DIR)%.c Makefile $(BONUS_DIR)libft.h $(BONUS_DIR)ft_printf_bonus.h
	@mkdir -p $(BONUS_OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

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
	@$(RM) $(OBJS) $(BONUS_OBJS) $(OBJS_BONUS)
	@make clean --no-print-directory -C $(LIBFT)
	@echo "$(RED)Directori eliminats amb èxit.$(DEF_COLOR)(printf)"
fclean:
	@$(RM) $(NAME)
	@$(RM) -r $(OBJS_DIR) $(BONUS_OBJS_DIR)
	@make fclean --no-print-directory -C $(LIBFT)
	@echo "$(RED)Directori eliminats amb èxit.$(DEF_COLOR)(printf)"
re:	clean all

.PHONY: all bonus clean fclean re
