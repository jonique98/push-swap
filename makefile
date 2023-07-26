CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = checker.c conquer.c initstructs.c inputcheck.c maketri.c merge.c nodeutil.c operators.c realsort.c sort.c trishape.c util.c
OBJECTS = $(SRCS:.c=.o)
INC = -I./
RMF = rm -f

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< $(INC)

clean :
	$(RMF) $(OBJECTS)

fclean : clean
	$(RMF) $(NAME) 

re : fclean all

.PHONY : claen fclaen all re