CC = -Wall -Wextra -Werror -g

NAME = ft_retro
SRC_PATH = ./srcs
HEADER_PATH = ./headers

LIB = -lncurses
INCLUDE = -I $(HEADER_PATH)

SRC =   $(SRC_PATH)/main.cpp\
        $(SRC_PATH)/NcurseManager.cpp\
        $(SRC_PATH)/GameEngine.cpp\
        $(SRC_PATH)/GameManager.cpp\
        $(SRC_PATH)/Bullet.cpp\
        $(SRC_PATH)/Enemy.cpp\
        $(SRC_PATH)/Player.cpp\

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(CC) -o $@ $(LIB) $^

%.o: %.cpp
	clang++ $(CC) $(INCLUDE) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re