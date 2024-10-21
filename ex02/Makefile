SRCS = tests.cpp Account.cpp
OFILES = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = account

all: $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean: 	
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all