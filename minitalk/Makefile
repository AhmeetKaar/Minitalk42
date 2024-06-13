NAME=serverclient.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
PRINTF=ft_printf/libftprintf.a

CLIENT = client
SERVER = server

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(PRINTF)
	$(CC) $(CFLAGS) server.c $(PRINTF) -o $(SERVER)

$(CLIENT): $(PRINTF)
	$(CC) $(CFLAGS) client.c $(PRINTF) -o $(CLIENT)

$(PRINTF):
	make -C ./ft_printf

clean:
	make clean -C ./ft_printf

fclean: clean
	make fclean -C ./ft_printf
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
