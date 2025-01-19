CPP = c++
CPPFLAGS = -Wall -Werror -Wextra

NAME = megaphone

SRC = ./megaphone.cpp

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CPP) $(CPPFLAGS) $-c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re