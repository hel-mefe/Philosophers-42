SRCS = errors.c exec.c init.c parsing.c philo.c utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = philo

MARK = " \033[1;31m _______  __   __  ___   ___      _______  _______  _______  _______  __   __  _______  ______    _______ \n\
\033[1;31m|       ||  | |  ||   | |   |    |       ||       ||       ||       ||  | |  ||       ||    _ |  |       |\n\
\033[1;33m|    _  ||  |_|  ||   | |   |    |   _   ||  _____||   _   ||    _  ||  |_|  ||    ___||   | ||  |  _____|\n\
\033[1;33m|   |_| ||       ||   | |   |    |  | |  || |_____ |  | |  ||   |_| ||       ||   |___ |   |_||_ | |_____ \n\
\033[1;33m|    ___||       ||   | |   |___ |  |_|  ||_____  ||  |_|  ||    ___||       ||    ___||    __  ||_____  |\n\
\033[1;33m|   |    |   _   ||   | |       ||       | _____| ||       ||   |    |   _   ||   |___ |   |  | | _____| |\n\
\033[1;31m|___|    |__| |__||___| |_______||_______||_______||_______||___|    |__| |__||_______||___|  |_||_______|\n\
							  \033[3;34m\n\n\t\t\t\t\t\t\t\t\t\t\t made by hel-mefe\n"
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\n\033[1;32m \t\t\t👾 --> PHILO HAS BEEN CREATED SUCCESSFLULY <-- 👾\n"
	@printf $(MARK)

all: $(NAME)
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
