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

SEED = 42

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

RESULTS = results

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
		@mkdir -p results
		./${NAME_DEFAUT_FT} ${SEED} > results/ft_defaut.txt ; ./${NAME_DEFAUT_STD} ${SEED} > results/std_defaut.txt ; diff results/ft_defaut.txt results/std_defaut.txt > results/diff_defaut.txt

map:	${NAME_MAP_FT} ${NAME_MAP_STD}
		@mkdir -p results
		./${NAME_MAP_FT} > results/ft_map.txt ; ./${NAME_MAP_STD} > results/std_map.txt ; diff results/ft_map.txt results/std_map.txt > results/diff_map.txt

vector:	${NAME_VECTOR_FT} ${NAME_VECTOR_STD}
		@mkdir -p results
		./${NAME_VECTOR_FT} > results/ft_vector.txt ; ./${NAME_VECTOR_STD} > results/std_vector.txt ; diff results/ft_vector.txt results/std_vector.txt > results/diff_vector.txt

stack:	${NAME_STACK_FT} ${NAME_STACK_STD}
		@mkdir -p results
		./${NAME_STACK_FT} > results/ft_stack.txt ; ./${NAME_STACK_STD} > results/std_stack.txt ; diff results/ft_stack.txt results/std_stack.txt > results/diff_stack.txt

clean:
		rm -rf $(OBJS_DEFAUT) $(OBJS_MAP) $(OBJS_VECTOR) $(OBJS_STACK) results/ft_defaut.txt results/std_defaut.txt results/diff_defaut.txt results/ft_map.txt results/std_map.txt results/diff_map.txt results/ft_vector.txt results/std_vector.txt results/diff_vector.txt results/ft_stack.txt results/std_stack.txt results/diff_stack.txt

fclean: clean
		rm -rf $(NAME_DEFAUT_FT) $(NAME_DEFAUT_STD) $(NAME_MAP_FT) $(NAME_MAP_STD) $(NAME_VECTOR_FT) $(NAME_VECTOR_STD) $(NAME_STACK_FT) $(NAME_STACK_STD)

re: fclean all

.PHONY: re all clean fclean