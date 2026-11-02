*This project has been created as part of the 42 curriculum by sicleerd.*

# Libft

## Description

**Libft** is the first project of the 42 curriculum. The goal is to build my own
C library, `libft.a`, by re-implementing a set of standard C library functions
along with additional utility functions. The library is meant to be reused in
all later 42 projects.

The project helps me understand how the standard functions work internally,
practice memory management (`malloc` / `free`), pointers, and string and memory
manipulation, and follow the 42 Norm.

The library is split into the following parts:

### Part 1 - Libc functions

Re-implementations of standard functions, with the same prototypes and
behavior as the originals (but prefixed with `ft_`):

- **Character checks / conversion:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`,
  `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- **String functions:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`,
  `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_atoi`
- **Memory functions:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`,
  `ft_memchr`, `ft_memcmp`, `ft_calloc`

### Part 2 - Additional functions

Functions that are not in the standard libc, or that are part of it in a
different form:

`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`,
`ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Linked lists

Functions to manipulate linked lists built on the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`,
`ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`

### Compilation

From the root of the repository:

```bash
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + make
```

The library is compiled with the flags `-Wall -Wextra -Werror`.

### Usage

Include the header in your source files and link against the library:

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

## Resources

### References

- [Linux manual pages](https://man7.org/linux/man-pages/) - reference for the
  behavior of every re-implemented libc function
- [GNU Make documentation](https://www.gnu.org/software/make/manual/)
- [42 Norm](https://github.com/42School/norminette) - coding standard enforced
  by `norminette`

### Use of AI


AI was used for the following tasks only:

- Finding edge cases for testing
- Reviewing the README