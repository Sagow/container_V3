SRCS =	main_stack.cpp

HEADERS =	RBnode.hpp	\
			RBtree.hpp	\
			map.hpp		\
			algorithm.hpp	\
			iterator.hpp	\
			vector.hpp	\
			stack.hpp

OBJS =  ${SRCS:.cpp=.o}

CC =	c++

FLAGS = -std=c++98 -Wall -Werror -Wextra -g3 -fsanitize=address -I.

NAME =  RBtest

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
		$(CC) $(FLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean