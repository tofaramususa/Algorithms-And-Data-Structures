NAME = sort

SRCS = mergeSort.cpp

CXX = c++
CXXFLAGS = -g3 --std=c++11 -Wall -Wextra -Werror -Iinclude -fsanitize=address

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
