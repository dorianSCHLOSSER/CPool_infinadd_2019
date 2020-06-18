##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## return
##

NAME	= infin_add

all:
	make -C ./lib/my all
	gcc -o  $(NAME) *.c -L./lib -lmy -g -Wall -Wextra

clean: fclean

fclean:
	rm -f $(NAME)

re: fclean all
