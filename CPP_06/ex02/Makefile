CPP       = c++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98
CHECK_FLAGS := $(CPP_FLAGS) -fsyntax-only

PROGRAM_NAME = Base

# ========= source =========
SRCDIR   := ./src
INCDIR   := ./include
INCLUDES := -I$(INCDIR)

SRC :=  $(SRCDIR)/main.cpp \
		$(SRCDIR)/Base.cpp \

OBJDIR      := objs
TEST_OBJDIR := test_objs
TEST_BINDIR := bin_tests

OBJS := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# ========= tests =========
TESTDIR    := tests
TEST_NAMES := serializer_spec

# 重要：出力先は TEST_BINDIR にする
TEST_BINS  := $(addprefix $(TEST_BINDIR)/,$(TEST_NAMES))


# ========= default =========
all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $@ $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -c $< -o $@

# ===== make dirs (一度だけ定義する) =====
$(TEST_OBJDIR):
	@mkdir -p $(TEST_OBJDIR)

$(TEST_BINDIR):
	@mkdir -p $(TEST_BINDIR)

# ===== per-test template =====
define BUILD_TEST_template
# compile -> test_objs/<name>.o
$(TEST_OBJDIR)/$(1).o: $(TESTDIR)/$(1).cpp | $(TEST_OBJDIR)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -c $$< -o $$@

# link -> bin_tests/<name>
$(TEST_BINDIR)/$(1): $(TEST_OBJDIR)/$(1).o $(HELPERS_OBJ) $(filter-out $(OBJDIR)/main.o,$(OBJS)) | $(TEST_BINDIR)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $$@ $$^
endef
$(foreach t,$(TEST_NAMES),$(eval $(call BUILD_TEST_template,$(t))))

# ===== build & run =====
build-tests: $(TEST_BINS)

run-tests: $(TEST_BINS)
	@set -e; \
	for t in $(TEST_BINS); do \
		echo "===== Running $$t ====="; \
		./$$t; \
	done

# run single: make run-test_02_stream_operators
run-%: $(TEST_BINDIR)/%
	./$<

# ===== clean =====
clean:
	rm -rf $(OBJDIR) $(TEST_OBJDIR)

fclean: clean
	rm -f $(PROGRAM_NAME)
	rm -rf $(TEST_BINDIR)

# ===== static check only =====
check lint:
	@echo "== Syntax / static check: src =="
	$(CPP) $(CHECK_FLAGS) $(INCLUDES) $(SRC)
# 	@echo "== Syntax / static check: tests =="
# 	$(CPP) $(CHECK_FLAGS) $(INCLUDES) $(HELPERS_SRC) $(TEST_SRCS)

re: fclean all

.PHONY: all clean fclean re build-tests run-tests run-% check lint


