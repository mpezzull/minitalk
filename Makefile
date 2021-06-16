SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o ft_minitalk_utils.o ft_minitalk_utils_2.o minitalk.h
	@$(CC) server.o ft_minitalk_utils.o ft_minitalk_utils_2.o -o $@
	@printf "$@ successfully build\n"

$(CLIENT) : client.o ft_minitalk_utils.o ft_minitalk_utils_2.o minitalk.h
	@$(CC) client.o ft_minitalk_utils.o ft_minitalk_utils_2.o -o $@
	@printf "$@ successfully build\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@rm -f *.o
	@printf ".o files deleted\n"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "binaries deleted\n"

re: fclean all