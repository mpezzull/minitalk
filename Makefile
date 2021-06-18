# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 16:25:03 by mpezzull          #+#    #+#              #
#    Updated: 2021/06/18 15:20:25 by mde-rosa         ###   ########.fr        #
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

SRCS_S_B	=	server_bonus.c \
				minitalk_utils_bonus.c \
				minitalk_utils_2_bonus.c \
				minitalk_utils_3_bonus.c


SRCS_C_B	=	client_bonus.c \
				minitalk_utils_bonus.c \
				minitalk_utils_2_bonus.c \
				minitalk_utils_3_bonus.c

NAME_C		=	client

NAME_S		=	server

NAME_C_B	=	client_bonus

NAME_S_B	=	server_bonus

CFLAGS		=	-Wall -Werror -Wextra

CC			=	gcc

OBJCS_C		=	$(SRCS_C:.c=.o)

OBJCS_S		=	$(SRCS_S:.c=.o)

OBJCS_C_B	=	$(SRCS_C_B:.c=.o)

OBJCS_S_B	=	$(SRCS_S_B:.c=.o)

.c.o		:
				$(CC)  -c $<

all			:	$(NAME_C) $(NAME_S)
			
$(NAME_C)		:	$(OBJCS_C)
				@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJCS_C)
			 	@echo "$@ successfully build"

$(NAME_S)		:	$(OBJCS_S)
				@$(CC) $(CFLAGS) -o $(NAME_S) $(OBJCS_S)
			 	@echo "$@ successfully build"

bonus		:	$(NAME_C_B) $(NAME_S_B)
			
$(NAME_C_B)		:	$(OBJCS_C_B)
				@$(CC) $(CFLAGS) -o $(NAME_C_B) $(OBJCS_C_B)
			 	@echo "$@ successfully build"

$(NAME_S_B)		:	$(OBJCS_S_B)
				@$(CC) $(CFLAGS) -o $(NAME_S_B) $(OBJCS_S_B)
			 	@echo "$@ successfully build"

clean		:
				@rm -f $(OBJCS_C)
				@rm -f $(OBJCS_S)
				@rm -f $(OBJCS_C_B)
				@rm -f $(OBJCS_S_B)
			 	@echo ".o files deleted"

fclean		:	clean
				@rm -f $(NAME_C)
				@rm -f $(NAME_S)
				@rm -f $(NAME_C_B)
				@rm -f $(NAME_S_B)
			 	@echo "binaries deleted"

re			:	fclean all

.PHONY		:	all bonus clean fclean re
