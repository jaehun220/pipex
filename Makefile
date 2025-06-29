# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 17:02:31 by jaehlee           #+#    #+#              #
#    Updated: 2025/06/24 17:02:31 by jaehlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c split.c utils.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cc $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

%.o : %.C
	cc $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
