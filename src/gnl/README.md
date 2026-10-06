# gnl

Reading a file descriptor line by line.

```c
#include "ft/get_next_line.h"
```

[← Back to the main README](../../README.md)

| Function | Purpose |
|---|---|
| [`get_next_line`](#get_next_line) | read the next line of a fd |

---

### get_next_line

```c
char	*get_next_line(int fd);
```

Reads the next line of `fd`. Each call resumes where the previous one stopped.

**Returns:** the line read, **newline `\n` included** (except for the last line of a file that
does not end with `\n`), in an allocated string to be freed by the caller.
Returns `NULL`:
- at end of file;
- if `read` fails;
- if an allocation fails;
- if `fd` is invalid (`fd < 0` or `fd >= MAX_FD`).

```c
char	*line;

line = get_next_line(fd);
while (line)
{
	ft_putstr_fd(line, 1);
	free(line);
	line = get_next_line(fd);
}
```

**Several fds:** calls can alternate between several fds open at the same time; each one keeps
its own position. The fds must be lower than `MAX_FD` (1024).

**Buffer size:** `get_next_line` reads in chunks of `BUFFER_SIZE` bytes (42 by default).
The value is chosen **when building the libft** (see the *Building* section of the
[main README](../../README.md#building)), not in the project that uses it.

**Warning:** if you stop reading a fd before its end, what was already read stays in memory for
that fd number. If another file is then opened with the same number, the first call will return
the end of the old file first. To avoid this, read the fd until `get_next_line` returns `NULL`.
