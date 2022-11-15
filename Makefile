# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 20:46:40 by jjin	           #+#    #+#              #
#    Updated: 2022/11/15 20:43:57 by jjin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

BONUS = bonus

SRCS = main.c libft.c init.c oper.c oper_utils.c algo.c algo_utils.c hard_sort.c

BONUS_SRCS = push_swap.c

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

RM = rm -f

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(BONUS) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJ)

clean :
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY :	all clean fclean re
