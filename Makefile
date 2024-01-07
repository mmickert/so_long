# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mickert <mickert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 13:07:09 by mickert           #+#    #+#              #
#    Updated: 2024/01/06 18:41:11 by mickert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
#CFLAGS = -g -fsanitize=address -Wunreachable-code

SRC = suorce/so_long.c suorce/floodfill.c suorce/parse_map.c suorce/map_utils.c suorce/pec.c suorce/minilib.c suorce/movements.c suorce/movements_utils.c

ODIR = ./obj
OBJ = $(SRC:suorce/%.c=$(ODIR)/%.o)

HEADER = includes/so_long.h
NAME = ./so_long

MINILIBDIR = minilibx
MINILIB = $(MINILIBDIR)/libmlx.a

LIBFTDIR = ./suorce/libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFT_OBJDIR = $(LIBFTDIR)/objectives

INC = -I ./includes -I $(LIBFTDIR)/includes
VPATH = suorce suorce/libft

LDFLAGS = -L$(MINILIBDIR) -lmlx -framework OpenGL -framework AppKit -lz

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) $(INC) -o $(NAME)

$(LIBFT): | $(LIBFT_OBJDIR)
	$(MAKE) -C $(LIBFTDIR)

$(MINILIB):
	$(MAKE) -C $(MINILIBDIR)

$(ODIR)/%.o: %.c $(HEADER) | $(ODIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(ODIR):
	@mkdir -p $@

$(LIBFT_OBJDIR):
	@mkdir -p $@

clean:
	rm -f $(ODIR)/*.o
	$(MAKE) -C $(MINILIBDIR) clean
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBDIR) clean
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
