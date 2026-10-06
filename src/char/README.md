# char

Character tests and conversions.

```c
#include "ft/ft_char.h"
```

[← Back to the main README](../../README.md)

| Function | Purpose |
|---|---|
| [`ft_isalpha`](#ft_isalpha) | letter? |
| [`ft_isdigit`](#ft_isdigit) | digit? |
| [`ft_isalnum`](#ft_isalnum) | letter or digit? |
| [`ft_isascii`](#ft_isascii) | ASCII character? |
| [`ft_isprint`](#ft_isprint) | printable character? |
| [`ft_iswhite_space`](#ft_iswhite_space) | whitespace character? |
| [`ft_tolower`](#ft_tolower) | uppercase → lowercase |
| [`ft_toupper`](#ft_toupper) | lowercase → uppercase |

Every `ft_is*` function returns **1** if the test is true, **0** otherwise.

---

### ft_isalpha

```c
int	ft_isalpha(int c);
```

Tests whether `c` is an ASCII letter (`a`–`z` or `A`–`Z`).

---

### ft_isdigit

```c
int	ft_isdigit(int c);
```

Tests whether `c` is a decimal digit (`0`–`9`).

---

### ft_isalnum

```c
int	ft_isalnum(int c);
```

Tests whether `c` is a letter or a digit (`ft_isalpha(c) || ft_isdigit(c)`).

---

### ft_isascii

```c
int	ft_isascii(int c);
```

Tests whether `c` is in the ASCII table (0 to 127).

---

### ft_isprint

```c
int	ft_isprint(int c);
```

Tests whether `c` is a printable character (32 to 126, space included).

---

### ft_iswhite_space

```c
int	ft_iswhite_space(int c);
```

Tests whether `c` is a whitespace character: space, `\t`, `\n`, `\v`, `\f` or `\r`
(equivalent to `isspace`).

---

### ft_tolower

```c
int	ft_tolower(int c);
```

**Returns:** the matching lowercase letter if `c` is uppercase, otherwise `c` unchanged.

---

### ft_toupper

```c
int	ft_toupper(int c);
```

**Returns:** the matching uppercase letter if `c` is lowercase, otherwise `c` unchanged.
