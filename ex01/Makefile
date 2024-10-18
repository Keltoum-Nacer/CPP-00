SRCS = contact.cpp phoneBook.cpp
OFILES = $(SRCS:.cpp=.o)
CC = g++
CFLAGS = -Wall -Wextra -Werror 
NAME = awesome

all: $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean: 	
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all