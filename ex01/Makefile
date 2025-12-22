
NAME		= fixed

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I. -g

SRCS		= Fixed.cpp \
			  main.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re