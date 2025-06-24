# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 17:17:53 by jaehlee           #+#    #+#              #
#    Updated: 2025/06/24 17:17:53 by jaehlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
        ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
        ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
        ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
        ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
        ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
        ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BNS_SRCS = ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c \
           ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c

OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BNS_SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -I.

ifdef WITH_BONUS
    OBJ_FILE = $(BONUS_OBJS)
else
    OBJ_FILE = $(OBJS)
endif

all: $(NAME)
$(NAME): $(OBJ_FILE)
	ar -rcs $@ $^
%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

bonus:
	@make WITH_BONUS=1 all

.PHONY : all clean fclean re bonus