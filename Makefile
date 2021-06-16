SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o ft_minitalk_utils.o ft_minitalk_utils_2.o minitalk.h
	@$(CC) server.o ft_minitalk_utils.o ft_minitalk_utils_2.o -o $@
	@echo "$@ successfully build"

$(CLIENT) : client.o ft_minitalk_utils.o ft_minitalk_utils_2.o minitalk.h
	@$(CC) client.o ft_minitalk_utils.o ft_minitalk_utils_2.o -o $@
	@echo "$@ successfully build"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@rm -f *.o
	@echo ".o files deleted"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "binaries deleted"

re: fclean all