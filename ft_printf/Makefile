NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRC_FILES = ft_printf ft_eval ft_print_char ft_print_hex ft_print_num ft_print_pointer ft_print_string ft_print_unbr ft_width_count ft_hex_flag
LIBFT_FILES = 		ft_strlen \
					ft_atoi \
					ft_memset \
					ft_bzero \
					ft_memcpy \
					ft_memmove \
					ft_memchr \
					ft_memcmp \
					ft_isalpha \
					ft_isdigit \
					ft_isalnum \
					ft_isascii \
					ft_isprint \
					ft_toupper \
					ft_tolower \
					ft_strchr \
					ft_strrchr \
					ft_strlcpy \
					ft_strlcat \
					ft_strnstr \
					ft_strncmp \
					ft_calloc \
					ft_strdup \
					ft_substr \
					ft_strjoin \
					ft_strtrim \
					ft_itoa \
					ft_putchar_fd \
					ft_putstr_fd \
					ft_putendl_fd \
					ft_putnbr_fd \
					ft_strmapi \
					ft_striteri \
					ft_split

SRCS = $(addprefix ./, $(addsuffix .c, $(SRC_FILES)))
LIBFT = $(addprefix libft/, $(addsuffix .c, $(LIBFT_FILES)))

OBJS = $(addprefix ./, $(addsuffix .o, $(SRC_FILES)))
LIBFT_OBJS = $(addprefix libft/, $(addsuffix .o, $(LIBFT_FILES)))

all: $(LIBFT_OBJS) $(NAME)

.c.o: $(SRCS) $(LIBFT)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(LIBFT_OBJS)
	@$(AR) $@ $^

bonus: re

clean:
	$(RM) $(OBJS) $(LIBFT_OBJS)
	make clean -C libft/

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re bonus