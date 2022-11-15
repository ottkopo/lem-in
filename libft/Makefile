# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 17:07:39 by akoykka           #+#    #+#              #
#    Updated: 2022/10/06 12:03:23 by akoykka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putchar.c \
	ft_putendl_fd.c ft_putendl.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr_fd.c \
	ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c \
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	ft_striteri.c ft_strjoin.c \
	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	ft_strncmp.c ft_strncpy.c \
	ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	ft_strsplit.c ft_strstr.c \
	ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_strlcat.c ft_strndup.c\
	ft_lst_add.c ft_lst_new.c ft_lst_iter.c ft_lst_map.c \
	ft_lst_del_one.c ft_lst_del.c ft_lst_push_top.c ft_lst_move_to_top.c\
	ft_memrcpy.c ft_lst_count.c ft_lst_get_tail.c\
	ft_lst_reverse.c get_next_line.c ft_invert_int_array.c\
	ft_mnode_insert.c ft_mnode_new.c ft_mnode_destroy.c \
	ft_isint.c ft_array_len.c ft_free_array.c


OBJECTS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror 
FLAGS += -g 

INCLUDES = includes/

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

$(OBJECTS): %.o:%.c Makefile
	@gcc $(FLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)


re: fclean all

norm:
	norminette $(SRCS)

.PHONY : all clean fclean re