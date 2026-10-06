# vector

Generic dynamic array: elements, all of the same size, are stored next to each other and the
array grows by itself when it is full.

```c
#include "ft/ft_vector.h"
```

[← Back to the main README](../../README.md)

```c
typedef struct s_vector
{
	void	*data;        /* the elements, side by side */
	size_t	len;          /* number of elements in use */
	size_t	capacity;     /* number of elements allocated */
	size_t	elem_size;    /* size of one element, in bytes */
}	t_vector;
```

`len` and `capacity` count **elements**, not bytes. They can be read directly, but must not be
modified by hand.

Functions returning an `int` return **1** on success and **0** on failure.

| Function | Purpose |
|---|---|
| [`ft_vector_new`](#ft_vector_new) | create a vector |
| [`ft_vector_add`](#ft_vector_add) | append an element |
| [`ft_vector_insert`](#ft_vector_insert) | insert an element at an index |
| [`ft_vector_get`](#ft_vector_get) | access an element |
| [`ft_vector_rm`](#ft_vector_rm) | remove an element |
| [`ft_vector_reserve`](#ft_vector_reserve) | reserve space in advance |
| [`ft_vector_free`](#ft_vector_free) | free the vector |

```c
t_vector	*v;
int			x;
size_t		i;

v = ft_vector_new(0, sizeof(int));
if (!v)
	return (1);
x = 42;
ft_vector_add(v, &x);              /* copies the value of x */
x = 7;
ft_vector_insert(v, &x, 0);        /* v = {7, 42} */
i = 0;
while (i < v->len)
	ft_printf("%d\n", *(int *)ft_vector_get(v, i++));
ft_vector_free(v);
```

**Growth:** when the vector is full, its capacity doubles (starting from
`VECTOR_MIN_CAPACITY`, i.e. 8, for an empty vector). Appending an element is therefore O(1)
on average.

**Storing pointers:** for a vector of `char *`, `elem_size` is `sizeof(char *)` and you pass the
**address** of the pointer: `ft_vector_add(v, &str)`. The vector never frees what the elements
point to: do it before calling `ft_vector_free`.

---

### ft_vector_new

```c
t_vector	*ft_vector_new(size_t capacity, size_t elem_size);
```

Creates an empty vector for elements of `elem_size` bytes, with room for `capacity` elements.
`capacity` may be 0: nothing is allocated until the first insertion.

**Returns:** the vector (to be freed with [`ft_vector_free`](#ft_vector_free)), or `NULL` if
`elem_size` is 0 or if the allocation fails.

---

### ft_vector_add

```c
int	ft_vector_add(t_vector *vector, const void *elem);
```

Copies `elem_size` bytes from `elem` to the end of the vector, growing it if needed.

**Returns:** `1` on success, `0` if `vector` or `elem` is `NULL` or if growing fails (the vector
is then unchanged).

---

### ft_vector_insert

```c
int	ft_vector_insert(t_vector *vector, const void *elem, size_t index);
```

Copies `elem_size` bytes from `elem` at position `index`. Elements from `index` onwards are
shifted by one slot. `index` can range from `0` to `len` included (`len` means appending at the
end). Costs O(n) because of the shift.

**Returns:** `1` on success, `0` if `vector` or `elem` is `NULL`, if `index > len`, or if
growing fails (the vector is then unchanged).

---

### ft_vector_get

```c
void	*ft_vector_get(t_vector *vector, size_t index);
```

**Returns:** a pointer to the element at `index`, to be cast to the right type
(`*(int *)ft_vector_get(v, i)`), or `NULL` if `vector` is `NULL` or if `index >= len`.

**Warning:** this pointer becomes invalid as soon as the vector grows (`ft_vector_add`,
`ft_vector_insert`, `ft_vector_reserve`), since the data may be moved. Do not keep it across
an insertion.

---

### ft_vector_rm

```c
void	ft_vector_rm(t_vector *vector, size_t index);
```

Removes the element at `index` by shifting the following ones by one slot. The capacity does
not shrink. If the element is a pointer, what it points to is not freed. Does nothing if
`vector` is `NULL` or if `index >= len`. Costs O(n) because of the shift.

---

### ft_vector_reserve

```c
int	ft_vector_reserve(t_vector *vector, size_t new_capacity);
```

Makes sure the vector can hold at least `new_capacity` elements, to avoid several reallocations
when the final size is known in advance. Never shrinks the capacity.

**Returns:** `1` if the capacity is enough (including when it already was), `0` if `vector` is
`NULL` or if the allocation fails (the vector is then unchanged).

---

### ft_vector_free

```c
void	ft_vector_free(t_vector *vector);
```

Frees the data and the structure of the vector. Does not free what the elements point to.
Does nothing if `vector` is `NULL`.
