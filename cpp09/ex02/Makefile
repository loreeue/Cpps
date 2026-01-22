NAME = merge

SRC = main.cpp PmergeMe.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

COLOR_COMPILATION = \033[38;2;0;200;100m
COLOR_CLEAN = \033[38;2;200;100;100m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@printf "$(COLOR_COMPILATION)✔ Compilation complete!$(RESET)\n"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(COLOR_CLEAN)✖ Objects cleaned!$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(COLOR_CLEAN)✖ Binary removed!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
