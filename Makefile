# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/14 08:14:29 by rcourtoi          #+#    #+#              #
#    Updated: 2020/08/14 08:14:31 by rcourtoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = clang
CFLAGS = -Wall -Wextra -Werror

LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L $(LIB_PATH)

INC_DIR = includes
INC_FLAG = -I $(INC_DIR) -lft

OBJ_DIR = obj

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
HEADER		=	./includes/ftls.h

SRC_DIR = src

SRC = main.c

all: $(NAME)

$(NAME): obj $(OBJS) $(LIB) $(HEADER)
	$(CC) $(OBJS) $(CFLAGS) $(INC_FLAG) $(LIB_LINK)  -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile 
	$(CC) $(CFLAGS) -I $(LIB_PATH) -I $(INC_DIR) -c $< -o $@

$(LIB):
	make -C $(LIB_PATH)

obj:
	mkdir -p obj

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJS)
	rm -Rf obj

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

debug: obj $(OBJS) $(LIB) $(HEADER)
	$(CC) $(CFLAGS) -g $(INC_FLAG) $(LIB_LINK) -o $@ $(OBJS)


.PHONY: all clean fclean re debug
