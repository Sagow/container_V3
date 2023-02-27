MAIN_DEFAUT =	main_defaut.cpp

MAIN_MAP =		main_map.cpp

MAIN_VECTOR =	main_vector.cpp

MAIN_STACK =	main_stack.cpp

STD =	-D STD

HEADERS =	RBnode.hpp	\
			RBtree.hpp	\
			map.hpp		\
			algorithm.hpp	\
			iterator.hpp	\
			vector.hpp	\
			stack.hpp

OBJS_DEFAUT =  ${MAIN_DEFAUT:.cpp=.o}

OBJS_MAP =  ${MAIN_MAP:.cpp=.o}

OBJS_VECTOR =  ${MAIN_VECTOR:.cpp=.o}

OBJS_STACK =  ${MAIN_STACK:.cpp=.o}


CC =	c++

FLAGS = -std=c++98 -Wall -Werror -Wextra -g3 -I. -Iiterators

NAME_DEFAUT_FT =  ft_defaut
NAME_DEFAUT_STD =  std_defaut
NAME_MAP_FT =  ft_map
NAME_MAP_STD =  std_map
NAME_VECTOR_FT =  ft_vector
NAME_VECTOR_STD =  std_vector
NAME_STACK_FT =  ft_stack
NAME_STACK_STD =  std_stack

all: defaut map vector stack

${NAME_DEFAUT_FT}:	${OBJS_DEFAUT}
		${CC} ${FLAGS} ${OBJS_DEFAUT} -o ${NAME_DEFAUT_FT}

${NAME_DEFAUT_STD}:	${OBJS_DEFAUT}
		${CC} ${FLAGS} ${STD} ${OBJS_DEFAUT} -o ${NAME_DEFAUT_STD}

${NAME_MAP_FT}:	${OBJS_MAP}
		${CC} ${FLAGS} ${OBJS_MAP} -o ${NAME_MAP_FT}

${NAME_MAP_STD}:	${OBJS_MAP}
		${CC} ${FLAGS} ${STD} ${OBJS_MAP} -o ${NAME_MAP_STD}

${NAME_VECTOR_FT}:	${OBJS_VECTOR}
		${CC} ${FLAGS} ${OBJS_VECTOR} -o ${NAME_VECTOR_FT}

${NAME_VECTOR_STD}:	${OBJS_VECTOR}
		${CC} ${FLAGS} ${STD} ${OBJS_VECTOR} -o ${NAME_VECTOR_STD}

${NAME_STACK_FT}:	${OBJS_STACK}
		${CC} ${FLAGS} ${OBJS_STACK} -o ${NAME_STACK_FT}

${NAME_STACK_STD}:	${OBJS_STACK}
		${CC} ${FLAGS} ${STD} ${OBJS_STACK} -o ${NAME_STACK_STD}

%.o: %.cpp
		$(CC) $(FLAGS) -o $@ -c $<

defaut:	${NAME_DEFAUT_FT} ${NAME_DEFAUT_STD}
		./${NAME_DEFAUT_FT} > ft_defaut.txt ; ./${NAME_DEFAUT_STD} > std_defaut.txt ; diff ft_defaut.txt std_defaut.txt > diff_defaut.txt

map:	${NAME_MAP_FT} ${NAME_DEFAUT_STD}
		./${NAME_MAP_FT} > ft_map.txt ; ./${NAME_MAP_STD} > std_map.txt ; diff ft_map.txt std_map.txt > diff_map.txt

vector:	${NAME_VECTOR_FT} ${NAME_VECTOR_STD}
		./${NAME_VECTOR_FT} > ft_vector.txt ; ./${NAME_VECTOR_STD} > std_vector.txt ; diff ft_vector.txt std_vector.txt > diff_vector.txt

stack:	${NAME_STACK_FT} ${NAME_STACK_STD}
		./${NAME_STACK_FT} > ft_stack.txt ; ./${NAME_STACK_STD} > std_stack.txt ; diff ft_stack.txt std_stack.txt > diff_stack.txt

clean:
		rm -rf $(OBJS_DEFAUT) $(OBJS_MAP) $(OBJS_VECTOR) $(OBJS_STACK)

fclean: clean
		rm -rf $(NAME_DEFAUT_FT) $(NAME_DEFAUT_STD) $(NAME_MAP_FT) $(NAME_MAP_STD) $(NAME_VECTOR_FT) $(NAME_VECTOR_STD) $(NAME_STACK_FT) $(NAME_STACK_STD)

re: fclean all

.PHONY: re all clean fclean