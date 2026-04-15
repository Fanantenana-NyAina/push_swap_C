*This project has been created as part of the 42 curriculum by tsirakot.*

# Description

**Libft** is a foundational project of the 42 curriculum.
Its goal is to build a personal C library by reimplementing a set of standard libc functions, as well as additional utility functions and basic linked list handling.

This project helps students:
- Understand how common C standard functions work internally
- Improve memory management skills
- Write clean, reusable, and well-structured C code
- Build a library that will be reused throughout future projects

The result is a static library (`libft.a`) containing general-purpose functions for string manipulation, memory handling, character checks, I/O helpers, and linked lists.

### Objective

The main objective of this project is to:

- Understand and implement the fundamental functions of the C library
- Master memory management and pointer manipulation
- Develop expertise in string manipulation, memory operations, and data structures
- Create a reusable library for future projects

---

## Instructions

### Compilation

To compile the library, use the provided Makefile:

```bash
make
```

This command will compile all the source files and create the static library `libft.a`.

### Cleanup

To remove compiled object files:

```bash
make clean
```

To remove object files and the library:

```bash
make fclean
```

To rebuild the entire project:

```bash
make re
```

### Usage

To use this library in your C programs, include the header file and link it to the library:

```c
#include "libft.h"
```

When compiling your program, link the library:

```bash
cc -Wall -Wextra -Werror your_program.c -L. -lft -o your_program

```

---

## Resources

### Documentation and References

- [C manual]
- [youtube]
- [google]

### AI Usage Statement

AI tools were used to facilitate this project in the following areas:

AI tools were used to facilitate this project in the following areas:

- **Documentation**: AI contributed to the documentation of standard complex functions in the C language.

- **Memory Safety**: AI helped identify memory leaks and buffer overflows in the code.

- **Output**: AI provided code output so I could compare it with the output of my own code.

- **Fixing**: AI fixed some functions I was stuck on.

---

## Library Contents

### Partie 1 - Functions of the Libc
Re-implementation of standard functions prefixed with `ft_` :
* **Character handling :** `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower`.
* **Memory management :** `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc`.
* **String management :** `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `strdup`.
* **Conversion :** `atoi`.

### Partie 2 - Additional functions
Fonctions non présentes dans la libc standard ou implémentées différemment :
* `ft_substr` : Extracts a substring from a string.
* `ft_strjoin` : Concatenates two strings.
* `ft_strtrim` : Trims specific characters from the beginning and end of a string.
* `ft_split` :Splits a string into an array of strings using a delimiter.
* `ft_itoa` : Converts an integer to a string.
* `ft_strmapi` / `ft_striteri` : Applies a function to each character of a string.
* `ft_putchar_fd` / `ft_putstr_fd` / `ft_putendl_fd` / `ft_putnbr_fd` : Output functions using file descriptors.

### Partie 3 - Linked lists
Using the t_list structure to manipulate dynamic lists:
* `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

## Notes

* The project complies with **Standard 42** ([Norminette](https://github.com))

* No external libraries are used.

* Compilation is handled by a **Makefile** with the flags `-Wall -Wextra -Werror`.

---
