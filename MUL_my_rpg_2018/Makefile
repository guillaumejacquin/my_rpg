##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

.PHONY:				all clean fclean re tests_run

CFLAGS				=	-Iinclude/

LDFLAGS				=	-lcsfml-graphics -g3 -lcsfml-audio -lcsfml-system -o$(NAME)

NAME				=	my_rpg

SRCS				=	src/mainc.c	\
					src/fonctions.c	\
					src/menu.c	\
					src/menu2.c \
					src/menu3.c	\
					src/level.c	\
					src/level_next.c \
					src/forge.c	\
					src/forge2.c \
					src/level1.c \
					src/level1_moves.c	\
					src/level2.c \
					src/level2_moves.c	\
					src/level3.c 	\
					src/level3_moves.c	\
					src/level1_gameplay.c	\
					src/attaque.c \
					src/pause.c   \
					src/attackl3.c \
					src/deplacementsl3.c \
					src/deplacementsl2.c \
					src/level2_attack.c

OBJS				=	$(SRCS:.c=.o)

all:				$(NAME)

$(NAME):			$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean:				clean
	$(RM) $(NAME)

re:				fclean all
