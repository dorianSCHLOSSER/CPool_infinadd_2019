##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## return
##

build_lib:
	gcc -c *.c
	ar rc libmy.a *.o
	rm *.o
copy_h:
	cp my.h ../../include/

copy_lib:	build_lib
	cp libmy.a ../

all:	fclean build_lib copy_lib copy_h clean

clean:
	rm -f *.o
	rm -f *.a

fclean:	clean
	rm -f *.o
	rm -f ../libmy.a
	rm -f *.a

re: all fclean
