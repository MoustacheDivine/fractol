NAME        =   fractol

CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror -g -I $(INCDIR) -I $(MLX) -I $(LIB)
CLINKS      =   -ldl -lglfw -pthread -lm

MLX         =   minilibx
LIBMLX      =   $(MLX)/libmlx42.a
LIB         =   Libstache-Divine
LIBFT       =   $(LIB)/libft.a

SRCDIR      =   src
INCDIR      =   includes
OBJDIR      =   obj

SRC         =   burning_ship colors ft_atolf hook julia main mandlebrot
SRCS        =   $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRC)))
OBJS        =   $(addprefix $(OBJDIR)/, $(SRC:=.o))


all: $(LIBFT) $(LIBMLX) $(NAME)


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) $(LIBFT) -o $(NAME) $(CLINKS)
	@echo "Compilation de $(NAME) terminée."


$(LIBFT):
	@$(MAKE) --quiet -C $(LIB)
	@echo "Libft compilée."


$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilation de $<"


$(OBJDIR):
	@mkdir -p $(OBJDIR)


clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) --quiet -C $(LIB) clean
	@echo "Nettoyage des fichiers objets."


fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --quiet -C $(LIB) fclean
	@echo "Nettoyage complet."


re: fclean all

norm:
	@echo "Norminette de $(NAME) dans $(SRCDIR) et $(INCDIR)..."
	@if norminette $(SRCDIR)/*.c $(INCDIR)/*.h | grep -v "OK!" | grep -q "Error!"; then \
		norminette $(SRCDIR)/*.c $(INCDIR)/*.h | grep -v "OK!" | \
		while read line; do \
			if echo $$line | grep -q "Error!"; then \
				echo "\033[0;31m$$line\033[0m"; \
			else \
				echo "$$line"; \
			fi; \
		done; \
	else \
		echo "\033[0;32mAll files are norminette friendly !\033[0m"; \
	fi


.PHONY: all clean fclean re norm