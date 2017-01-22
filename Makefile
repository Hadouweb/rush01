CC = clang++
CFLAGS = -Werror -Wall -Wextra -O2 -g

NAME = ft_gkrellm

SRC_PATH = ./srcs

INCLUDES = -I ./headers -I ./SFML/include

LDENV = DYLD_FRAMEWORK_PATH="$(shell pwd)/SFML/Frameworks"
# export DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks"

LIBS =	-framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks -lncurses

SRC =   $(SRC_PATH)/main.cpp\
        $(SRC_PATH)/SfmlDisplay.class.cpp\
        $(SRC_PATH)/ModuleName.class.cpp\
        $(SRC_PATH)/Monitor.class.cpp\

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling all"
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

rmsfml:
	rm -rf SFML

ldenv:
	@echo export $(LDENV)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re