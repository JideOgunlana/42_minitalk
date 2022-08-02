
SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FT_PRINTF_OBJ = ../ft_printf/libftprintf.a
FT_PRINTF_DIR = ../ft_printf

SERVER_DIR = ./
CLIENT_DIR = ./

SERVER_FILES = server.c
CLIENT_FILES = client.c

SERVER_OBJS = $(addprefix $(SERVER_DIR), $(addsuffix .o, $(SERVER)))
CLIENT_OBJS = $(addprefix $(CLIENT_DIR), $(addsuffix .o, $(CLIENT)))


all: $(CLIENT) $(SERVER)

$(SERVER): ft_minitalk.h $(FT_PRINTF_OBJ) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(FT_PRINTF_OBJ) -o $(SERVER)

$(CLIENT): ft_minitalk.h $(FT_PRINTF_OBJ) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(FT_PRINTF_OBJ) -o $(CLIENT)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	make -C $(FT_PRINTF_DIR) clean

re: fclean all

.PHONY: clean fclean re ft_printf all bonus
