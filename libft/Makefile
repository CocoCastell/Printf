# Variables

NAME = libft.a
CC = cc
CFLAGS = -Werror -Wextra -Wall -I includes
SRCS_DIR = src/
OBJS_DIR = obj/
AR = ar

SRC = ft_itoa.c ft_putnbr_fd.c ft_strmapi.c ft_putstr_fd.c ft_strncmp.c ft_atoi.c ft_split.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_strchr.c ft_strrchr.c ft_calloc.c ft_memcmp.c ft_strdup.c ft_strtrim.c ft_isalnum.c ft_memcpy.c ft_striteri.c ft_substr.c ft_isalpha.c ft_memmove.c ft_strjoin.c ft_tolower.c ft_isascii.c ft_memset.c ft_strlcat.c ft_toupper.c ft_isdigit.c ft_putchar_fd.c ft_strlcpy.c ft_isprint.c ft_putendl_fd.c ft_strlen.c

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
BONUS_OBJS = $(addprefix $(OBJS_DIR), $(BONUS:.c=.o))

$(shell mkdir -p $(OBJS_DIR))


# Colors

DEF_COLOR = \033[0;39m
GREY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Rules

all:	$(NAME)

$(NAME): $(OBJS)
	@$(AR) -rcs $@ $^
	@echo "Biblioteca $(MAGENTA)$(NAME)$(DEF_COLOR) creada amb èxit."

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c	Makefile includes/libft.h
	@$(CC) $(CFLAGS) -c -o $@ $<

bonus:	$(OBJS) $(BONUS_OBJS)
	@$(AR) -rcs $(NAME) $^

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)Fitxers eliminats amb èxit.$(DEF_COLOR)(libft)"

fclean:	clean
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Directori eliminats amb èxit.$(DEF_COLOR)(libft)"

re:	fclean all

.PHONY: all clean fclean re
