CPP = g++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

PROGRAM_NAME = Accounts

SRCDIR := ./
INCDIR := ./includes

SRC :=  $(SRCDIR)/Account.cpp \
        $(SRCDIR)/Tests.cpp

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
