# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 20:27:21 by bpouchep          #+#    #+#              #
#    Updated: 2020/07/15 20:27:23 by bpouchep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_atoi.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_split.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_strchr.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_memmove.c \
				ft_bzero.c \
				ft_memcmp.c \
				ft_memchr.c \
				ft_calloc.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strtrim.c \
				ft_strmapi.c \
				ft_itoa.c \

SRCS_BONUS  =   ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS  =   $(SRCS_BONUS:.c=.o)

CC          =	gcc

RM			=   rm -f

CFLAGS		=   -Wall -Wextra -Werror

LIB         =   ar rc $(NAME)

all:		$(NAME)

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
				$(LIB) $(OBJS)

bonus:      $(OBJS) $(OBJS_BONUS)
				$(LIB) $(OBJS_BONUS) $(OBJS)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
