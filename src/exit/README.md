# exit

Exiting the program on an error, with a message.

```c
#include "ft/ft_exit.h"
```

[← Back to the main README](../../README.md)

| Function | Purpose |
|---|---|
| [`exit_error`](#exit_error) | print an error and exit |
| [`exit_free`](#exit_free) | free a pointer, print an error and exit |

The message is written to standard error (fd 2) in the format required by several 42 subjects
(so_long, push_swap…):

```
Error
<message>
```

For a free-form message, use [`ft_dprintf`](../ft_printf/README.md#ft_dprintf)`(2, ...)` then
`exit`.

---

### exit_error

```c
void	exit_error(char *error_msg, int exit_status);
```

Writes `Error\n`, then `error_msg` followed by a `\n`, to standard error, then ends the program
with `exit(exit_status)`. If `error_msg` is `NULL`, only the `Error` line is written.
Never returns.

```c
if (fd < 0)
	exit_error("cannot open map", 1);
```

---

### exit_free

```c
void	exit_free(char *error_msg, void *ptr, int exit_status);
```

Frees `ptr` (which may be `NULL`), then calls [`exit_error`](#exit_error). Never returns.

Only frees one pointer: for a structure that itself holds allocations, free everything before
calling [`exit_error`](#exit_error).
