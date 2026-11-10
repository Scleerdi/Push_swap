# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sicleerd <sicleerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/09/28 16:47:01 by sicleerd      #+#    #+#                  #
<<<<<<< HEAD
#    Updated: 2026/11/05 16:15:10 by gshabait      ########   odam.nl          #
=======
<<<<<<< HEAD
#    Updated: 2026/11/06 14:05:45 by gshabait      ########   odam.nl          #
=======
#    Updated: 2026/11/05 16:15:10 by gshabait      ########   odam.nl          #
>>>>>>> 80f7be8 (I don't knnow)
>>>>>>> 79d6236d72b9ef04a8214f7a34ce1525a1f99da0
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE =	isalpha isdigit isalnum isascii isprint strlen memset bzero \
			memcpy memmove strlcpy strlcat toupper tolower strchr \
			strrchr strncmp memchr memcmp strnstr atoi \
			calloc strdup \
			substr strjoin strtrim split itoa strmapi striteri \
			putchar_fd putstr_fd putendl_fd putnbr_fd \
			lstnew lstadd_front lstadd_back lstsize lstlast lstdelone \
<<<<<<< HEAD
			lstclear lstiter lstmap printf printbase\
=======
<<<<<<< HEAD
			lstclear lstiter lstmap printf printbase \
=======
			lstclear lstiter lstmap printf printbase\
>>>>>>> 80f7be8 (I don't knnow)
>>>>>>> 79d6236d72b9ef04a8214f7a34ce1525a1f99da0
			sqrt
SOURCE := $(SOURCE:%=ft_%.c)
OBJECT := $(SOURCE:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECT)
	@echo "Compiling Libft"
	@ar -rcs $(NAME) $(OBJECT)

$(OBJECT): $(SOURCE)
	@cc -Wall -Werror -Wextra -c $(SOURCE)

clean:
	@-rm -f $(OBJECT)

fclean: clean
	@-rm -f $(NAME)

re: fclean all