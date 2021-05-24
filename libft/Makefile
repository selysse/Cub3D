# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 20:01:41 by gselyse           #+#    #+#              #
#    Updated: 2021/03/11 18:44:58 by gselyse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

INCLUDES = libft.h

FLAGS = -Wall -Wextra -Werror

SRCS = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
		ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
		ft_substr.c  ft_putchar_fd.c ft_putstr_fd.c ft_split.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_itoa.c \
		ft_strtrim.c ft_strjoin.c ft_isspaces.c get_next_line.c \
		get_next_line_utils.c ft_space.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c\

OBJ = $(SRCS:%.c=%.o)

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c\



BONUS_OBJ = $(SRCS_BONUS:%.c=%.o)

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c $(INCLUDES)
		$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUS_OBJ) $(OBJ)
		@ar rcs $(NAME) $(BONUS_OBJ)
		@ranlib $(NAME)
clean:
		@rm -rf $(OBJ) $(BONUS_OBJ)

fclean:	clean 
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus %.o