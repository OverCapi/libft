# ft_printf

Formatted output, compatible with `printf` for the supported conversions and flags.

```c
#include "ft/ft_printf.h"
```

[← Back to the main README](../../README.md)

| Function | Purpose |
|---|---|
| [`ft_printf`](#ft_printf) | write to standard output |
| [`ft_dprintf`](#ft_dprintf) | write to a file descriptor |

---

### ft_printf

```c
int	ft_printf(const char *format, ...);
```

Writes `format` to standard output, replacing each conversion (`%…`) with the matching
argument.

**Returns:** the number of characters written, or `-1` on error (see [Errors](#errors)).

---

### ft_dprintf

```c
int	ft_dprintf(int fd, const char *format, ...);
```

Like [`ft_printf`](#ft_printf), but writes to `fd`. Typically used for error messages:

```c
ft_dprintf(2, "error: cannot open %s\n", path);
```

**Returns:** the number of characters written, or `-1` on error (in particular if `fd < 0`).

---

## Conversion format

```
%[flags][width][.precision][z]conversion
```

### Conversions

| Conversion | Argument | Output |
|---|---|---|
| `%c` | `int` | one character (`'\0'` is written too) |
| `%s` | `char *` | a string; `(null)` if the pointer is `NULL` |
| `%p` | `void *` | an address in hexadecimal with `0x`; `(nil)` if `NULL` |
| `%d`, `%i` | `int` | a signed integer in base 10 |
| `%u` | `unsigned int` | an unsigned integer in base 10 |
| `%x`, `%X` | `unsigned int` | an unsigned integer in lowercase / uppercase hexadecimal |
| `%%` | — | a `%` (flags and width are ignored) |

### Flags

| Flag | Effect | Conversions |
|---|---|---|
| `-` | left-justify within the width (pad on the right with spaces) | all |
| `0` | pad on the left with `0` instead of spaces; ignored with `-` or a precision | `d i u x X` |
| `#` | prefix a non-zero value with `0x` / `0X` | `x X` |
| `+` | always print the sign (`+42`) | `d i` |
| space | put a space before positive numbers (` 42`); ignored with `+` | `d i` |

### Width and precision

- **Width** (`%8d`): minimum number of characters; the result is padded with spaces (or `0`
  with the `0` flag).
- **Precision** (`%.3d`, `%.5s`):
  - for `d i u x X`: minimum number of digits, padded with `0` on the left. With a precision
    of `0`, the value `0` prints no digit;
  - for `s`: maximum number of characters printed. With a `NULL` string and a precision below
    6, nothing is printed (like glibc).

### Length modifier

| Modifier | Effect |
|---|---|
| `z` | the argument is a `size_t` for `u x X`, an `ssize_t` for `d i` |

```c
ft_printf("[%5d] [%-5d] [%05d]\n", 42, 42, 42);         /* [   42] [42   ] [00042] */
ft_printf("[%+d] [% d] [%.4d]\n", 42, 42, 42);          /* [+42] [ 42] [0042] */
ft_printf("[%#x] [%#08X] [%.3s]\n", 255, 255, "hello"); /* [0xff] [0X0000FF] [hel] */
ft_printf("len = %zu\n", ft_strlen("hello"));           /* len = 5 */
```

### Not supported

Variable width or precision (`%*d`), the `h`, `hh`, `l`, `ll`, `j`, `t` modifiers, and the
`%f`, `%e`, `%g`, `%o`, `%n` conversions.

## Errors

Both functions return `-1` if:
- `format` is `NULL`;
- the format ends with a lone `%` (`"abc%"`);
- a `write` call fails;
- (`ft_dprintf` only) `fd < 0`.

An unknown conversion (`%y`, `%5k`…) is not an error: it is copied as is.
