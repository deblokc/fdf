# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnaton <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 16:39:01 by tnaton            #+#    #+#              #
#    Updated: 2022/02/23 17:21:42 by tnaton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c src libft
vpath %.h src libft
vpath %.o src

NAME = fdf

source = fdf.c map.c plat.c screen.c line.c hook.c hud.c type1.c type2.c \
		 line2.c fdf2.c map2.c screen2.c hud2.c hud3.c hud4.c norm.c\
		 hook2.c hook3.c hook4.c hook5.c hud5.c

LIBFT = libft/libft.a

MLX = minilibx/libmlx_Linux.a

object = $(addprefix src/,$(source:.c=.o))

$(NAME) : $(object) $(LIBFT) $(MLX)
	gcc $(object) $(MLX) $(LIBFT) -lXext -lX11 -lm -Iminilibx -o $@

-include libft/Makefile

$(LIBFT) : $(source) $(BONUS) libft.h
	$(MAKE) bonus -C ./libft

$(MLX) :
	$(MAKE) -C ./minilibx

.PHONY: debug
debug : $(object) $(LIBFT) $(MLX)
	gcc -g3 -fsanitize=address $(object) $(MLX) $(LIBFT) -lXext -lX11 -lm -Iminilibx -o $@

.PHONY: all
all : $(NAME)

.PHONY: clean
clean :
	rm -rf $(object)
	$(MAKE) clean -C ./libft

.PHONY: fclean
fclean :
	rm -rf $(NAME) $(object)
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./minilibx 

.PHONY: re
re : fclean all

$(object) : libft.h fdf.h

.SECONDARY: $(object)
