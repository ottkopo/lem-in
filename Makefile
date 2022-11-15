# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 13:55:47 by okoponen          #+#    #+#              #
#    Updated: 2022/10/21 15:06:32 by akoykka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= lem-in
LIBFT 	= ./libft
FLAGS   = -Wall -Wextra -Werror -g 
SRC_DIR = srcs/

DEF_COLOR = \033[0;39m
RED = \033[1;91m
GREEN = \033[1;92m

SRC_FILES = read_input
SRC_FILES += hash
SRC_FILES += lem_in
SRC_FILES += queue
SRC_FILES += queue2
SRC_FILES += queue3
SRC_FILES += read_utils
SRC_FILES += rules
SRC_FILES += error
SRC_FILES += alter_flow
SRC_FILES += march_ants
SRC_FILES += march_moves
SRC_FILES += march_utils
SRC_FILES += evaluation
SRC_FILES += bfs_utils
SRC_FILES += parse
SRC_FILES += is_valid_input

OBJ	= $(addsuffix .o, $(SRC_FILES))
INCLUDES = -I includes/

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) Makefile
	make -C $(LIBFT)
	gcc $(FLAGS) -Llibft -lft $(OBJ) -o $(NAME) $(INCLUDES)
	@echo "$(GREEN)Lem_in completed$(DEF_COLOR)"

$(OBJ) : %.o: $(SRC_DIR)%.c Makefile
	gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

clean :
	rm -f $(OBJ)
	make clean -C libft/

fclean : clean
	rm -f $(NAME)
	rm -f $(OBJ)
	make fclean -C libft/

re : fclean all
