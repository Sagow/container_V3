SRCS =	main_test.cpp

HEADERS =	vector.hpp \
			algorithm.hpp

OBJS =  ${SRCS:.cpp=.o}

CC =	c++

FLAGS = -std=c++98 -Wall -Werror -Wextra -fsanitize=address -g3

NAME =  Vector

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp ${HEADERS}
		$(CC) $(FLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean