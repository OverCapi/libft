# libft

A personal C library, born from the 42 **libft** project and extended project after project.

It contains:
- a reimplementation of part of the libc (`ft_strlen`, `ft_memcpy`, `ft_atoi`…);
- utility functions (`ft_split`, `ft_strtrim`, `ft_atoi_safe`…);
- two data structures: a **linked list** and a **vector** (dynamic array);
- **ft_printf** / **ft_dprintf** with flags, width and precision;
- **get_next_line**, with multi-fd support.

All the code follows the **42 Norm** (checked with `norminette`).

---

## Modules

Each category has its own header in `includes/ft/` and its documentation in its source folder.

| Category | Header | Content | Documentation |
|---|---|---|---|
| char | `ft/ft_char.h` | character tests and conversions | [src/char/README.md](src/char/README.md) |
| mem | `ft/ft_mem.h` | raw memory manipulation | [src/mem/README.md](src/mem/README.md) |
| str | `ft/ft_str.h` | strings | [src/str/README.md](src/str/README.md) |
| converter | `ft/ft_converter.h` | string ↔ number conversions | [src/converter/README.md](src/converter/README.md) |
| write | `ft/ft_write.h` | writing to a file descriptor | [src/write/README.md](src/write/README.md) |
| linked_list | `ft/ft_linked_list.h` | singly linked list `t_list` | [src/linked_list/README.md](src/linked_list/README.md) |
| vector | `ft/ft_vector.h` | dynamic array `t_vector` | [src/vector/README.md](src/vector/README.md) |
| ft_printf | `ft/ft_printf.h` | `ft_printf`, `ft_dprintf` | [src/ft_printf/README.md](src/ft_printf/README.md) |
| gnl | `ft/get_next_line.h` | line-by-line reading | [src/gnl/README.md](src/gnl/README.md) |
| exit | `ft/ft_exit.h` | exiting the program on error | [src/exit/README.md](src/exit/README.md) |

---

## Layout

```
libft/
├── Makefile
├── includes/
│   ├── libft.h              # main header: includes every category
│   └── ft/                  # one public header per category
│       ├── ft_char.h
│       ├── ft_mem.h
│       └── ...
├── src/
│   ├── char/                # sources + README of the category
│   ├── mem/
│   ├── ...
│   ├── ft_printf/           # also holds ft_printf_internal.h (private)
│   └── gnl/                 # also holds get_next_line_internal.h (private)
└── build/                   # generated objects (build/obj/<category>/*.o)
```

The `*_internal.h` headers in `src/` are **private**: they declare functions internal to
ft_printf and gnl and are not exposed to projects using the library.

---

## Building

| Command | Effect |
|---|---|
| `make` | builds `libft.a` |
| `make so` | builds `libft.so` (shared library; on Linux, requires `-fPIC` in `CFLAGS`) |
| `make clean` | removes `build/` |
| `make fclean` | removes `build/`, `libft.a` and `libft.so` |
| `make re` | `fclean` then `make` |

The get_next_line buffer size is set when building the library (42 by default):

```sh
make re CFLAGS="-Wall -Wextra -Werror -D BUFFER_SIZE=128"
```

---

## Using it in a project

In the project's Makefile:

```make
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I includes -I $(LIBFT_DIR)/includes

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)
```

In the code, include the whole library or a single category:

```c
#include "libft.h"          /* every category */
#include "ft/ft_str.h"      /* string functions only */
```

Linking is selective: only the functions actually used (and the ones they depend on) end up in
the final executable, since each function has its own `.o`.

---

## Conventions

- **Prefix**: every public function starts with `ft_`, except `get_next_line`, `exit_error`
  and `exit_free`.
- **Memory**: a function returning an allocated pointer (`ft_strdup`, `ft_split`, `ft_itoa`,
  `get_next_line`…) leaves it to the caller, who must free it. It returns `NULL` if the
  allocation fails.
- **`NULL` arguments**: the library's own functions (`ft_strjoin`, `ft_substr`, `ft_split`,
  `ft_strtrim`…) and the write functions return `NULL` or do nothing when given `NULL`.
  The libc reimplementations (`ft_strlen`, `ft_strdup`, `ft_strcmp`, `ft_memcmp`…) behave like
  the original: a `NULL` makes them crash.
- **Success / failure**: functions that can fail without returning a pointer (`ft_atoi_safe`,
  `ft_vector_add`, `ft_vector_insert`, `ft_vector_reserve`) return `1` on success and `0` on
  failure.
- **File descriptors**: the write functions do nothing if `fd < 0`.

---

## Dependencies between categories

Some categories use functions from other categories. They are all built into `libft.a`, so
there is nothing to do on the user side; this only matters to know what to keep when
extracting part of the library.

| Category | Uses |
|---|---|
| converter | char |
| write | str |
| vector | mem |
| ft_printf | str, mem, char |
| gnl | str |
| exit | write |

char, mem, str and linked_list have no dependency.

---

## Norm

```sh
norminette src includes
```
