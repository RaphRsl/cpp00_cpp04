# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsl <rsl@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 17:16:36 by rsl               #+#    #+#              #
#    Updated: 2024/01/05 18:29:07 by rsl              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################## Colors ##########################

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_CYAN=\033[0;36m
COLOUR_END=\033[0m

########################## Variables ##########################

NAME		= PhoneBook

OBJDIR = .objFiles

FILES		= main Contact PhoneBook

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Contact.hpp PhoneBook.hpp

CC			= c++
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# GREEN		=	\e[92;5;118m
# YELLOW		=	\e[93;5;226m
# GRAY		=	\e[33;2;37m
# RESET		=	\e[0m
# CURSIVE		=	\e[33;3m

########################## Rules ##########################

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus norm

########################## Banner ########################## Nancyj-improved

# BANNER = 
#  a88888b.  888888ba   888888ba                a8888a   a8888a          d8'                       a8888a  d88  
# d8'   `88  88    `8b  88    `8b              d8' ..8b d8' ..8b        d8'                       d8' ..8b  88  
# 88        a88aaaa8P' a88aaaa8P'              88 .P 88 88 .P 88       d8'      .d8888b. dP.  .dP 88 .P 88  88  
# 88         88         88                     88 d' 88 88 d' 88      d8'       88ooood8  `8bd8'  88 d' 88  88  
# Y8.   .88  88         88                     Y8'' .8P Y8'' .8P     d8'        88.  ...  .d88b.  Y8'' .8P  88  
#  Y88888P'  dP         dP                      Y8888P   Y8888P     88          `88888P' dP'  `dP  Y8888P  d88P 
#                                 oooooooooooo                                                                  
