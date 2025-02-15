CPP = g++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

PROGRAM_NAME = Zombie

SRCDIR := ./
INCDIR := ./includes

SRC :=  $(SRCDIR)/main.cpp \
        $(SRCDIR)/Zombie.cpp \
        $(SRCDIR)/newZombie.cpp \
        $(SRCDIR)/randomChump.cpp \
		

INCLUDES := -I$(INCDIR)

OBJDIR := objs
OBJS := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $@ $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re
