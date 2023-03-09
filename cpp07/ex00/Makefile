NAME	= template
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp
OBJ		= ${SRC:.cpp=.o}

all: ${NAME}

$(NAME): ${OBJ}
	${CC} ${FLAGS} -o ${NAME} ${SRC}

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

clean:
	rm -f ${OBJ}
	@printf '\e[5m❌ \e[0m\x1b[38;2;255;140;0mObjects removed\x1b[0m\e[5m ❌\n\e[0m'

fclean: clean
	rm -f ${NAME}
	@printf '\e[5m🚨 \e[0m\x1b[38;2;200;0;20mBinary removed\x1b[0m\e[5m 🚨\n\e[0m'

re: fclean all

.PHONY: all clean fclean re
