# mem

Raw memory manipulation, byte by byte.

```c
#include "ft/ft_mem.h"
```

[← Back to the main README](../../README.md)

| Function | Purpose |
|---|---|
| [`ft_memset`](#ft_memset) | fill an area with a byte |
| [`ft_bzero`](#ft_bzero) | fill an area with zeros |
| [`ft_memcpy`](#ft_memcpy) | copy an area (no overlap) |
| [`ft_memmove`](#ft_memmove) | copy an area (overlap allowed) |
| [`ft_memchr`](#ft_memchr) | search for a byte |
| [`ft_memcmp`](#ft_memcmp) | compare two areas |
| [`ft_calloc`](#ft_calloc) | allocate a zero-initialized area |

These functions behave like their libc counterparts.

---

### ft_memset

```c
void	*ft_memset(void *s, int c, size_t n);
```

Fills the first `n` bytes of `s` with the byte `(unsigned char)c`.

**Returns:** `s`.

---

### ft_bzero

```c
void	ft_bzero(void *s, size_t n);
```

Sets the first `n` bytes of `s` to zero.

---

### ft_memcpy

```c
void	*ft_memcpy(void *dest, const void *src, size_t n);
```

Copies `n` bytes from `src` to `dest`. The two areas **must not overlap** (use
[`ft_memmove`](#ft_memmove) in that case).

**Returns:** `dest`, or `NULL` if both `dest` and `src` are `NULL`.

---

### ft_memmove

```c
void	*ft_memmove(void *dest, const void *src, size_t n);
```

Copies `n` bytes from `src` to `dest`. The areas **may overlap**: the copy is done in the right
direction so the source is not overwritten.

**Returns:** `dest`, or `NULL` if both `dest` and `src` are `NULL`.

---

### ft_memchr

```c
void	*ft_memchr(const void *s, int c, size_t n);
```

Searches for the byte `(unsigned char)c` in the first `n` bytes of `s`.

**Returns:** a pointer to the first occurrence, or `NULL` if the byte is not found.

---

### ft_memcmp

```c
int	ft_memcmp(const void *s1, const void *s2, size_t n);
```

Compares the first `n` bytes of `s1` and `s2`, as `unsigned char`.

**Returns:** `0` if the areas are identical, otherwise the difference between the first two
differing bytes (negative if `s1 < s2`, positive if `s1 > s2`).

---

### ft_calloc

```c
void	*ft_calloc(size_t nmemb, size_t size);
```

Allocates an array of `nmemb` elements of `size` bytes, entirely set to zero.

**Returns:** the allocated area (to be freed with `free`), or `NULL` if the allocation fails or
if `nmemb * size` overflows a `size_t`.
