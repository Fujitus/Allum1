##
## Makefile for alum1 in /home/costa_d/Documents/alum1
## 
## Made by Arnaud Costa
## Login   <costa_d@epitech.net>
## 
## Started on  Mon Feb  8 17:19:02 2016 Arnaud Costa
## Last update Sun Feb 21 16:21:46 2016 Arnaud Costa
##

CC	= gcc

RM	= rm -rf

NAME	= allum1

CFLAGS	= -Wall -Wextra -W -ansi -pedantic -Iinclude

SRC	= src/plateau.c \
	  src/tools.c \
	  src/bob.c \
	  src/get_next_line.c \
	  src/tcheck_param.c \
	  src/ia_xor.c \
	  src/main.c

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	 $(CC) $(OBJ) -o $(NAME)

all:	  $(NAME)

clean:
	  $(RM) $(OBJ)

fclean:		clean
	  $(RM) $(NAME)

re:	  fclean all

.PHONY:	  all clean fclean re
