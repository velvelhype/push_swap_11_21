NAME = push_swap

SOURCES = *.c

FLAGS = -Wall -Wextra -Werror

ALL:  push_swap
@gcc $(SOURCES) $(FLAGS)