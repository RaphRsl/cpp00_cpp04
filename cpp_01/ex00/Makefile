# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsl <rsl@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 17:16:36 by rsl               #+#    #+#              #
#    Updated: 2024/01/11 21:44:50 by rsl              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################## Colors ##########################

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_ORANGE=\033[0;33m
COLOUR_BLUE=\033[0;34m
COLOUR_CYAN=\033[0;36m
COLOUR_DARK_GRAY=\033[0;90m
COLOUR_END=\033[0m

GREEN_FLASH		=	\e[92;5;118m
RED_FLASH		=	\e[91;5;196m
ORANGE_FLASH	=	\e[93;5;226m
RESET_FLASH		=	\e[0m

########################## Variables ##########################

NAME		= Brainz

OBJDIR = .objFiles

FILES		= main Zombie newZombie randomChump

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Zombie.hpp

CC			= c++
FLAGS		= -std=c++98 -Wall -Wextra -Werror
RM			= rm -rf

########################## Rules ##########################

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	@echo $(BANNER)
	@echo "$(COLOUR_DARK_GRAY)Compiling files...$(COLOUR_END)"
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@echo "$(GREEN_FLASH)↪$(RESET_FLASH) Finished, $(COLOUR_BLUE)$(NAME)$(COLOUR_END) is ready, all files have been $(COLOUR_GREEN)compiled$(COLOUR_END).\n"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@echo "$(COLOUR_GREEN)Compiling $<...$(COLOUR_END)"
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@
	@sleep .033
	@printf "\033[1A"
	@printf "\033[K"

clean:
	@echo "$(COLOUR_DARK_GRAY)Cleaning files...$(COLOUR_END)"
	@$(RM) $(OBJDIR) $(OBJ)
	@echo "$(ORANGE_FLASH)↪$(RESET_FLASH) Finished, $(COLOUR_BLUE)code files$(COLOUR_END) have been $(COLOUR_ORANGE)cleaned$(COLOUR_END)."

fclean: clean
	@echo "$(COLOUR_DARK_GRAY)Cleaning binaries...$(COLOUR_END)"
	@$(RM) $(NAME)
	@echo "$(RED_FLASH)↪$(RESET_FLASH) Finished, $(COLOUR_BLUE)$(NAME) and binaries$(COLOUR_END) have been $(COLOUR_RED)deleted$(COLOUR_END)."

re: fclean all

.PHONY: all clean fclean re bonus norm

########################## Banner ########################## AINSI SHADOW
                                                                                                                                            

BANNER		= "$(COLOUR_CYAN)"   \
" ██████╗██████╗ ██████╗     ██████╗  ██╗        ██╗    ███████╗██╗  ██╗ ██████╗  ██████╗ \n"\
"██╔════╝██╔══██╗██╔══██╗   ██╔═████╗███║       ██╔╝    ██╔════╝╚██╗██╔╝██╔═████╗██╔═████╗\n"\
"██║     ██████╔╝██████╔╝   ██║██╔██║╚██║      ██╔╝     █████╗   ╚███╔╝ ██║██╔██║██║██╔██║\n"\
"██║     ██╔═══╝ ██╔═══╝    ████╔╝██║ ██║     ██╔╝      ██╔══╝   ██╔██╗ ████╔╝██║████╔╝██║\n"\
"╚██████╗██║     ██║███████╗╚██████╔╝ ██║    ██╔╝       ███████╗██╔╝ ██╗╚██████╔╝╚██████╔╝\n"\
" ╚═════╝╚═╝     ╚═╝╚══════╝ ╚═════╝  ╚═╝    ╚═╝        ╚══════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝  rroussel\n"\
"$(COLOUR_END)" 

########################## Banner syntax ########################## 

# BANNER		= "$(COLOUR_CYAN)"   \
# " ██████╗██████╗ ██████╗     ██████╗  ██████╗         ██╗    ███████╗██╗  ██╗ ██████╗  ██╗\n"\
# "██╔════╝██╔══██╗██╔══██╗   ██╔═████╗██╔═████╗       ██╔╝    ██╔════╝╚██╗██╔╝██╔═████╗███║\n"\
# "██║     ██████╔╝██████╔╝   ██║██╔██║██║██╔██║      ██╔╝     █████╗   ╚███╔╝ ██║██╔██║╚██║\n"\
# "██║     ██╔═══╝ ██╔═══╝    ████╔╝██║████╔╝██║     ██╔╝      ██╔══╝   ██╔██╗ ████╔╝██║ ██║\n"\
# "╚██████╗██║     ██║███████╗╚██████╔╝╚██████╔╝    ██╔╝       ███████╗██╔╝ ██╗╚██████╔╝ ██║\n"\
# " ╚═════╝╚═╝     ╚═╝╚══════╝ ╚═════╝  ╚═════╝     ╚═╝        ╚══════╝╚═╝  ╚═╝ ╚═════╝  ╚═╝ rroussel\n"\ --> SHIFT ALT KEY_UP
# "$(COLOUR_END)" 	
