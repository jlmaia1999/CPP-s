NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp 

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS)
	@echo created
clean:	

fclean: clean
	rm -f $(NAME)
	@echo cleaned

re: fclean all

.PHONY: all clean fclean re