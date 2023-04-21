
SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
UTILS_BONUS = client_bonus_utils

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FT_PRINTF_OBJ = ./$(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_DIR = ./ft_printf

FILE_PATH = ./src/

BONUS_PATH = ./bonus/src/

SERVER_FILES = server.c
CLIENT_FILES = client.c

SERVER_BONUS_FILES = ./bonus/server_bonus.c
CLIENT_BONUS_FILES = ./bonus/client_bonus.c
BONUS_UTILS = ./bonus/client_bonus_utils.c


SERVER_OBJS = $(addprefix $(FILE_PATH), $(addsuffix .o, $(SERVER)))
CLIENT_OBJS = $(addprefix $(FILE_PATH), $(addsuffix .o, $(CLIENT)))

SERVER_BONUS_OBJS = $(addprefix $(BONUS_PATH), $(addsuffix .o, $(SERVER_BONUS)))
CLIENT_BONUS_OBJS = $(addprefix $(BONUS_PATH), $(addsuffix .o, $(CLIENT_BONUS)))
UTILS_BONUS_OBJS = $(addprefix $(BONUS_PATH), $(addsuffix .o, $(UTILS_BONUS)))


# colours
GREEN = \033[1;32m
BLUE = \033[1;34m
RESET = \e[0m

all: $(SERVER) $(CLIENT)
	@printf "$(BLUE)server and client$(RESET) $(GREEN)compiled successfully$(RESET)"

$(SERVER): $(FT_PRINTF_OBJ) $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(FT_PRINTF_OBJ) -o $(SERVER)

$(CLIENT): $(FT_PRINTF_OBJ) $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(FT_PRINTF_OBJ) -o $(CLIENT)

$(SERVER_BONUS): $(FT_PRINTF_OBJ) $(SERVER_BONUS_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(FT_PRINTF_OBJ) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(FT_PRINTF_OBJ) $(CLIENT_BONUS_OBJS) $(UTILS_BONUS_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(UTILS_BONUS_OBJS) $(FT_PRINTF_OBJ) -o $(CLIENT_BONUS)

$(FT_PRINTF_OBJ):
	make -C $(FT_PRINTF_DIR)
	make clean -C $(FT_PRINTF_DIR)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
	@printf "$(BLUE)server_bonus and client_bonus(RESET) $(GREEN)compiled successfully$(RESET)"

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS) $(UTILS_BONUS_OBJS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	$(RM) -f $(FT_PRINTF_OBJ)

re: fclean all

.PHONY: clean fclean re ft_printf all bonus
