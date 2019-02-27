#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 16:18:37 by acarlson          #+#    #+#              #
#    Updated: 2019/02/26 15:41:35 by acarlson         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang
SRC = src/
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -Wall -Wextra -g
OBJDIR = .obj/
INCLUDES = -I includes/ -I libft/includes/ -I minilibx_macos/
FRAMEWORKS = -framework OpenGL -framework AppKit
FILES = main parse struct key_funcs mouse_funcs util\
		mandelbrot julia ship lyapunov
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addprefix $(OBJDIR), $(addsuffix .o, $(FILES)))
LIBS = -L libft/ -lft -L minilibx_macos/ -lmlx
NAME = fractol
DNAME = d_$(NAME)

CL_CYAN = \033[0;36m
CL_GREEN = \033[0;32m
CL_RED = \033[0;31m
CL_WHITE = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OFILES)
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) $(CFLAGS) $(INCLUDES) $(FRAMEWORKS) $(LIBS) $(OFILES) -o $(NAME)
	@echo "  $(CL_WHITE)+ $(NAME) : Compiled $(CL_GREEN)$@$(CL_WHITE)"

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	@echo " $(shell \
		if [ -d $(OBJDIR) ]; \
		then \
			echo " $(CL_WHITE)- $(NAME) : Removing $(CL_RED)$(OBJDIR)$(CL_WHITE) with$(CL_RED)"; \
			ls $(OBJDIR) | wc -w | tr -d '[:blank:]'; echo "$(CL_WHITE)object files"; \
			rm -Rf $(OBJDIR); \
		else \
			echo " $(CL_WHITE)# $(NAME) : Nothing to clean"; \
		fi) "

fclean: clean
	@make -C libft/ fclean
	@echo " $(shell \
		if [ -f $(NAME) ]; \
		then \
			echo " $(CL_WHITE)- $(NAME) : Removing  $(CL_RED)$(NAME)$(CL_WHITE)"; \
			rm -f $(NAME); \
		else \
			echo " $(CL_WHITE)# $(NAME) : Nothing to fclean"; \
		fi) "

re: fclean all

$(addprefix $(OBJDIR), %.o): $(addprefix $(SRC), %.c)
	@$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<

$(OBJDIR):
	@echo " $(shell \
	if [ ! -d $(OBJDIR) ]; \
	then \
		mkdir $(OBJDIR); \
		echo " + $(NAME) : Created  $(CL_GREEN)$(OBJDIR)$(CL_WHITE)$(CL_WHITE)"; \
fi) "

tags:
	find . -type f -iname "*.[ch]" | etags -

j:
	@make -C libft/
	@make -C minilibx_macos/
	$(CC) $(DFLAGS) $(INCLUDES) $(FRAMEWORKS) $(LIBS) $(addprefix $(SRC), $(CFILES)) -o $(DNAME)

k: fclean
	rm -f $(DNAME)
	rm -rf *.dSYM
	rm -f TAGS

# Makes re, but does not remake libs
l:
	rm -Rf $(OBJDIR)
	rm -f $(NAME)
	make all

fsan:
	$(CC) $(DFLAGS) $(INCLUDES) $(FRAMEWORKS) $(LIBS) $(addprefix $(SRC), $(CFILES)) -o $(DNAME) -fsanitize=address
