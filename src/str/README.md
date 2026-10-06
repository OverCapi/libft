# str

String functions.

```c
#include "ft/ft_str.h"
```

[← Back to the main README](../../README.md)

| Function | Purpose | Allocates |
|---|---|---|
| [`ft_strlen`](#ft_strlen) | length of a string | |
| [`ft_strchr`](#ft_strchr) | first occurrence of a character | |
| [`ft_strrchr`](#ft_strrchr) | last occurrence of a character | |
| [`ft_strnstr`](#ft_strnstr) | search for a substring | |
| [`ft_strcmp`](#ft_strcmp) | comparison | |
| [`ft_strncmp`](#ft_strncmp) | comparison on `n` characters | |
| [`ft_strlcpy`](#ft_strlcpy) | size-bounded copy | |
| [`ft_strlcat`](#ft_strlcat) | size-bounded concatenation | |
| [`ft_striteri`](#ft_striteri) | apply a function to each character | |
| [`ft_strdup`](#ft_strdup) | duplicate a string | yes |
| [`ft_substr`](#ft_substr) | extract a substring | yes |
| [`ft_strjoin`](#ft_strjoin) | concatenate two strings | yes |
| [`ft_strtrim`](#ft_strtrim) | remove characters at both ends | yes |
| [`ft_strmapi`](#ft_strmapi) | build a transformed string | yes |
| [`ft_split`](#ft_split) | split on a separator | yes |
| [`ft_free_split`](#ft_free_split) | free the result of `ft_split` | |

The allocating functions return `NULL` if the allocation fails; the result must be freed by the
caller.

---

### ft_strlen

```c
size_t	ft_strlen(const char *str);
```

**Returns:** the number of characters in `str`, not counting the final `'\0'`.

---

### ft_strchr

```c
char	*ft_strchr(const char *s, int c);
```

Searches for the first occurrence of the character `c` in `s`. If `c` is `'\0'`, returns a
pointer to the final `'\0'`.

**Returns:** a pointer to the character found, or `NULL`.

---

### ft_strrchr

```c
char	*ft_strrchr(const char *s, int c);
```

Like [`ft_strchr`](#ft_strchr), but searches for the **last** occurrence.

**Returns:** a pointer to the character found, or `NULL`.

---

### ft_strnstr

```c
char	*ft_strnstr(const char *big, const char *little, size_t len);
```

Searches for `little` in `big`, reading at most `len` characters of `big`. The substring must
fit entirely within those `len` characters.

**Returns:** a pointer to the start of the occurrence in `big`, `big` if `little` is empty, or
`NULL` if nothing is found.

---

### ft_strcmp

```c
int	ft_strcmp(const char *s1, const char *s2);
```

Compares `s1` and `s2` character by character, as `unsigned char`.

**Returns:** `0` if the strings are identical, a negative value if `s1 < s2`, a positive value
if `s1 > s2`.

---

### ft_strncmp

```c
int	ft_strncmp(const char *s1, const char *s2, size_t n);
```

Like [`ft_strcmp`](#ft_strcmp), but compares at most `n` characters.

**Returns:** `0` if the first `n` characters are identical (or if `n` is 0), otherwise the
difference between the first differing characters.

---

### ft_strlcpy

```c
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
```

Copies `src` into `dst`, writing at most `size - 1` characters followed by a `'\0'`.
If `size` is 0, `dst` is not modified.

**Returns:** the length of `src`. If it is `>= size`, the copy was truncated.

---

### ft_strlcat

```c
size_t	ft_strlcat(char *dst, const char *src, size_t size);
```

Appends `src` to the end of `dst`. `size` is the **total** size of the `dst` buffer: at most
`size - strlen(dst) - 1` characters are appended, and the result ends with `'\0'`.

**Returns:** the length of the string it tried to create (`strlen(dst) + strlen(src)`).
If it is `>= size`, the result was truncated. If `size <= strlen(dst)`, nothing is copied and
the function returns `size + strlen(src)`.

---

### ft_striteri

```c
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
```

Calls `f(i, &s[i])` on each character of `s`, which lets `f` modify it in place.
Does nothing if `s` or `f` is `NULL`.

---

### ft_strdup

```c
char	*ft_strdup(const char *s);
```

**Returns:** an allocated copy of `s`, or `NULL` if the allocation fails.

---

### ft_substr

```c
char	*ft_substr(char const *s, unsigned int start, size_t len);
```

Extracts the substring of `s` starting at index `start`, at most `len` characters long.

**Returns:** the allocated substring; an empty string if `start` is past the end of `s`;
`NULL` if `s` is `NULL` or if the allocation fails.

---

### ft_strjoin

```c
char	*ft_strjoin(char const *s1, char const *s2);
```

**Returns:** a new allocated string holding `s1` followed by `s2`, or `NULL` if either is
`NULL` or if the allocation fails. `s1` and `s2` are not freed.

---

### ft_strtrim

```c
char	*ft_strtrim(char const *s1, char const *set);
```

Removes from the start and the end of `s1` every character found in `set`.

```c
ft_strtrim("  -hello-  ", " -");   /* "hello" */
```

**Returns:** the allocated string, or `NULL` if `s1` or `set` is `NULL` or if the allocation
fails.

---

### ft_strmapi

```c
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

Builds a new string where each character is `f(i, s[i])`.

**Returns:** the allocated string, or `NULL` if `s` or `f` is `NULL` or if the allocation fails.

---

### ft_split

```c
char	**ft_split(char const *s, char c);
```

Splits `s` into words separated by the character `c`. Consecutive, leading and trailing
separators are skipped: there is never an empty word.

```c
ft_split("  a bb  c ", ' ');   /* {"a", "bb", "c", NULL} */
```

**Returns:** an allocated array of allocated strings, terminated by `NULL`, to be freed with
[`ft_free_split`](#ft_free_split). Returns `NULL` if `s` is `NULL` or if an allocation fails
(in that case, everything allocated so far is freed).

---

### ft_free_split

```c
void	ft_free_split(char **strs);
```

Frees each string of a `NULL`-terminated array, then the array itself. Meant for the result of
[`ft_split`](#ft_split). Does nothing if `strs` is `NULL`.
