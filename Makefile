# Name of the binary
CLIENT_NAME		= client
SERVER_NAME		= server

CLIENT_NAME_BONUS		= client_bonus
SERVER_NAME_BONUS		= server_bonus

# Source files
CLIENT_SRCS   = client.c
SERVER_SRCS		= server.c

CLIENT_SRCS_BONUS   = client_bonus.c
SERVER_SRCS_BONUS		= server_bonus.c

# Compiler Flags
CC	= cc
CFLAGS = -Wall -Werror -Wextra -g

# Header files
HEADER  = libft/libft.a

# Object files
CLIENT_OBJS   = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS		= $(SERVER_SRCS:.c=.o)

CLIENT_OBJS_BONUS   = $(CLIENT_SRCS_BONUS:.c=.o)
SERVER_OBJS_BONUS		= $(SERVER_SRCS_BONUS:.c=.o)

# Default target
all: $(CLIENT_NAME) $(SERVER_NAME)

bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

.SILENT:

$(CLIENT_NAME): $(HEADER) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(HEADER)
	echo $(GREEN)"Building $(CLIENT_NAME)"$(DEFAULT);

$(SERVER_NAME): $(HEADER) $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(HEADER)
	echo $(GREEN)"Building $(SERVER_NAME)"$(DEFAULT);

$(CLIENT_NAME_BONUS): $(HEADER) $(CLIENT_OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME_BONUS) $(CLIENT_OBJS_BONUS) $(HEADER)
	echo $(GREEN)"Building $(CLIENT_NAME_BONUS)"$(DEFAULT);

$(SERVER_NAME_BONUS): $(HEADER) $(SERVER_OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME_BONUS) $(SERVER_OBJS_BONUS) $(HEADER)
	echo $(GREEN)"Building $(SERVER_NAME_BONUS)"$(DEFAULT);

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Linking libft
$(HEADER):
	make -C libft

# Remove all object files
clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)
	make -C libft clean
	echo $(RED)"Removing $(CLIENT_NAME) & $(SERVER_NAME) object files"$(DEFAULT);

clean_bonus:
	rm -f $(CLIENT_OBJS_BONUS) $(SERVER_OBJS_BONUS)
	make -C libft clean
	echo $(RED)"Removing $(CLIENT_NAME_BONUS) & $(SERVER_NAME_BONUS) object files"$(DEFAULT);

# Remove all files
fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)
	make -C libft fclean
	echo $(RED)"Removing $(CLIENT_NAME) & $(SERVER_NAME)"$(DEFAULT);

fclean_bonus: clean_bonus
	rm -f $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)
	make -C libft fclean
	echo $(RED)"Removing $(CLIENT_NAME_BONUS) & $(SERVER_NAME_BONUS)"$(DEFAULT);

# Rebuild everything
re: fclean all
	echo $(GREEN)"Rebuilding everything"$(DEFAULT);

re_bonus: fclean_bonus bonus
	echo $(GREEN)"Rebuilding everything"$(DEFAULT);

.PHONY: all all_bonus clean clean_bonus fclean  fclean_bonus re re_bonus

# Colours
DEFAULT = "\033[39m"
GREEN   = "\033[32m"
RED     = "\033[31m"
