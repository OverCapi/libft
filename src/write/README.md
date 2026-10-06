# write

Writing to a file descriptor (`1` for standard output, `2` for standard error…).

```c
#include "ft/ft_write.h"
```

[← Back to the main README](../../README.md)

| Function | Purpose |
|---|---|
| [`ft_putchar_fd`](#ft_putchar_fd) | write a character |
| [`ft_putstr_fd`](#ft_putstr_fd) | write a string |
| [`ft_putendl_fd`](#ft_putendl_fd) | write a string followed by `\n` |
| [`ft_putnbr_fd`](#ft_putnbr_fd) | write an integer |

All these functions do nothing if `fd < 0`. `write` errors are not reported.
To write formatted text, see [`ft_dprintf`](../ft_printf/README.md#ft_dprintf).

---

### ft_putchar_fd

```c
void	ft_putchar_fd(char c, int fd);
```

Writes the character `c` to `fd`.

---

### ft_putstr_fd

```c
void	ft_putstr_fd(char *s, int fd);
```

Writes the string `s` to `fd`, in a single `write` call. Does nothing if `s` is `NULL`.

---

### ft_putendl_fd

```c
void	ft_putendl_fd(char *s, int fd);
```

Writes the string `s` followed by a newline to `fd`. Does nothing if `s` is `NULL`.

---

### ft_putnbr_fd

```c
void	ft_putnbr_fd(int n, int fd);
```

Writes the integer `n` in base 10 to `fd`, `INT_MIN` included.
