CPP = g++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g

PROGRAM_NAME = Materia

SRCDIR := src
INCDIR := include

SRC :=  $(SRCDIR)/Character.cpp \
		$(SRCDIR)/AMateria.cpp \
		$(SRCDIR)/Cure.cpp \
		$(SRCDIR)/Ice.cpp \
		$(SRCDIR)/main.cpp \
		$(SRCDIR)/MateriaSource.cpp
		

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
