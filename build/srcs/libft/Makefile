# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sicleerd <sicleerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/09/28 16:47:01 by sicleerd      #+#    #+#                  #
#    Updated: 2026/10/12 11:56:29 by sicleerd      ########   odam.nl          #
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
			lstclear lstiter lstmap
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