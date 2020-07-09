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


HEADER	=	include

OBJS		=	${SRCS:.c=.o}

CC =		gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
				${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				ar rc ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
