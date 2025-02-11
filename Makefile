CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

NAME = endgame

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj maps

clean:
	rm -rf obj

uninstall:
	rm -rf obj maps path.txt $(NAME)

reinstall: uninstall all
