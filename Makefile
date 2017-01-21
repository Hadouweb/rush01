FLAGS = -Wall -Wextra -Werror

NAME = ft_gkrellm
SRC_PATH = ./srcs
HEADER_PATH = ./headers

LIB = -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML_2.4.1/Frameworks -lncurses
INCLUDE = -I $(HEADER_PATH) -I ./SFML_2.4.1/include

SRC =   $(SRC_PATH)/main.cpp\
        $(SRC_PATH)/SfmlDisplay.class.cpp\

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -o $@ $(OBJ) -rpath ./lib/SFML_2.4.1/extlibs $(LIB) $(INCLUDE)

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $< $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
