# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plang <plang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 12:36:37 by plang             #+#    #+#              #
#    Updated: 2024/07/10 14:14:36 by plang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= @cc

CFLAGS	= -Wall -Werror -Wextra

SRCS	= philo.c \
			philo_parsing.c \
			philo_initialization.c \
			philo_creator.c \
			philo_routine.c \
			philo_monitor_routine.c \
			philo_destroyer.c \
			philo_utils1.c \
			philo_utils2.c

OBJS	= $(SRCS:.c=.o)

$(NAME):		$(OBJS)
	$(CC)		$(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Philosophers gathered!"

clean:
	@rm -f		$(OBJS)
	@echo "Removed the knives!"

fclean:	clean
	@rm -f		$(NAME)
	@echo "Philosophers dismissed!"

re:	fclean		$(NAME)

.PHONY:	all clean fclean re