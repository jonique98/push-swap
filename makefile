CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS =	$(wildcard ./src/*.c)
OBJECTS = $(SRCS:.c=.o)
INC = -I./src/

BNSNAME = checker
BNSSRCS = $(wildcard ./bnssrc/*.c)
BNSOBJECTS = $(BNSSRCS:.c=.o)
GNLINC = -I./bnssrc/

RMF = rm -f

all : $(NAME)

bonus : $(BNSNAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(BNSNAME) : $(BNSOBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

src/%.o : %.c
	$(CC) $(CFLAGS) -c $< $(INC)

bnssrc/%.o : %.c
	$(CC) $(CFLAGS) -c $< $(INC) $(GNLINC)

clean :
	$(RMF) $(OBJECTS) $(BNSOBJECTS)

fclean : clean
	$(RMF) $(NAME) $(BNSNAME)

re : fclean all

.PHONY : clean fclean all re bonus
