NAME = minitalk.a
SERVER_SRCS = ./main_server.c ./utils/exception.c
CLIENT_SRCS = ./main_client.c ./utils/exception.c
SERVER = server
CLIENT = client
LIBFT = libft.a
LIBFT_DIR = ./libft
FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ./ft_printf


CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(CLIENT) $(SERVER)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)


$(SERVER): $(SERVER_OBJS)
		$(CC) $(CFLAGS) ./$(LIBFT_DIR)/$(LIBFT) ./$(FT_PRINTF_DIR)/$(FT_PRINTF) -o server $(SERVER_OBJS)

$(CLIENT): $(CLIENT_OBJS)
		$(CC) $(CFLAGS) ./$(LIBFT_DIR)/$(LIBFT) ./$(FT_PRINTF_DIR)/$(FT_PRINTF) -o client $(CLIENT_OBJS)

clean:
	make clean -C ./libft
	make clean -C ./ft_printf
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	$(RM) $(NAME) server client

re: fclean all

.PHONY: all server client clean fclean re