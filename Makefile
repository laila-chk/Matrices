# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 01:43:09 by waboutzo          #+#    #+#              #
#    Updated: 2022/11/11 05:52:47 by waboutzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
LIBFT = src/libft/libft.a
RM = rm -rf
CC = cc
HEADER = src/include/miniRT.h
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit#-I /Users/${USER}/.brew/opt/readline/include #-g -fsanitize=address
OBJ=$(SRCS:.c=.o)

#PARSING	=  hhhhh guess how will do the parsing XD

SRCS	=  #$(addsuffix .c, $(addprefix src/parsing/, $(PARSING)))
	
.c.o:
	@$(CC)  $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(HEADER) main.c $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) main.c -o $(NAME)

$(LIBFT) :
	@make -C src/libft
clean :
	@make clean -C src/libft
	@$(RM) $(OBJ)

fclean : clean
	@make fclean -C src/libft
	@$(RM) $(NAME)

re : fclean all

.PHONY:			all clean fclean re bonus