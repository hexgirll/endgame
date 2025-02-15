NAME = endgame

SRCDIR = src
INCDIR = inc
OBJDIR = obj
LIBDIR = resource/raylib/lib

SRC_FILES = $(wildcard $(SRCDIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror -std=c11 -I$(INCDIR)
LFLAGS = $(LIBDIR)/libraylib.a -lm -ldl -lpthread

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

uninstall: clean
	rm -f $(NAME)

reinstall: uninstall all

