# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 16:25:03 by mpezzull          #+#    #+#              #
#    Updated: 2021/06/17 16:50:15 by mpezzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_S		=	server.c \
				minitalk_utils.c \
				minitalk_utils_2.c \
				minitalk_utils_3.c


SRCS_C		=	client.c \
				minitalk_utils.c \
				minitalk_utils_2.c \
				minitalk_utils_3.c

NAME_C		=	client

NAME_S		=	server

CFLAGS		=	-Wall -Werror -Wextra

CC			=	gcc

OBJCS_C		=	$(SRCS_C:.c=.o)

OBJCS_S		=	$(SRCS_S:.c=.o)

.c.o		:
				$(CC)  -c $<

all			:	$(NAME_C) $(NAME_S)
			
$(NAME_C)		:	$(OBJCS_C)
				@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJCS_C)
			 	@echo "$@ successfully build"

$(NAME_S)		:	$(OBJCS_S)
				@$(CC) $(CFLAGS) -o $(NAME_S) $(OBJCS_S)
			 	@echo "$@ successfully build"

clean		:
				@rm -f $(OBJCS_C)
				@rm -f $(OBJCS_S)
			 	@echo ".o files deleted"

fclean		:	clean
				@rm -f $(NAME_C)
				@rm -f $(NAME_S)
			 	@echo "binaries deleted"

re			:	fclean all

.PHONY		:	all clean fclean re
