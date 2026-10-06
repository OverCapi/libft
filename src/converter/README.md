# converter

Conversions between strings and numbers.

```c
#include "ft/ft_converter.h"
```

[← Back to the main README](../../README.md)

| Function | Purpose |
|---|---|
| [`ft_atoi`](#ft_atoi) | string → `int`, like `atoi` |
| [`ft_atoi_safe`](#ft_atoi_safe) | string → `int`, with error detection |
| [`ft_itoa`](#ft_itoa) | `int` → allocated string |

---

### ft_atoi

```c
int	ft_atoi(const char *nptr);
```

Converts the beginning of `nptr` to an `int`, like `atoi`:
1. skips leading whitespace (see `ft_iswhite_space`);
2. reads **one** optional `+` or `-` sign;
3. reads digits and stops at the first non-digit character.

**Returns:** the number read, or `0` if there is no digit.

There is no way to detect an error: `"0"`, `"abc"` and `""` all return `0`, and a number
outside the `int` range gives a wrong result. To validate user input, use
[`ft_atoi_safe`](#ft_atoi_safe).

---

### ft_atoi_safe

```c
int	ft_atoi_safe(const char *nptr, int *out);
```

Converts `nptr` to an `int`, checking that the **whole** string is a valid number:
- whitespace allowed at the start only;
- one optional `+` or `-` sign;
- at least one digit;
- nothing after the digits (not even a space);
- value between `INT_MIN` and `INT_MAX`.

**Returns:** `1` on success, with the result written to `*out`; `0` otherwise, and `*out` is
left unchanged. Also returns `0` if `nptr` or `out` is `NULL`.

```c
int	n;

if (!ft_atoi_safe(argv[1], &n))
	exit_error("invalid number", 1);
```

| Input | Return | `*out` |
|---|---|---|
| `"42"`, `"  -42"`, `"+0"` | 1 | 42, -42, 0 |
| `"-2147483648"` | 1 | `INT_MIN` |
| `"2147483648"` | 0 | unchanged (overflow) |
| `"12abc"`, `"12 "` | 0 | unchanged (trailing characters) |
| `""`, `"-"`, `"abc"` | 0 | unchanged (no digit) |

---

### ft_itoa

```c
char	*ft_itoa(int n);
```

**Returns:** the decimal representation of `n` in an allocated string (`INT_MIN` included),
or `NULL` if the allocation fails.
