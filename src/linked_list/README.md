# linked_list

Generic singly linked list: each node holds a `content` pointer to any kind of data.

```c
#include "ft/ft_linked_list.h"
```

[← Back to the main README](../../README.md)

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

A list is represented by a pointer to its first node (`t_list *`). An empty list is a `NULL`
pointer. Functions that change the head of the list take its address (`t_list **`).

| Function | Purpose |
|---|---|
| [`ft_lstnew`](#ft_lstnew) | create a node |
| [`ft_lstadd_front`](#ft_lstadd_front) | add a node at the front |
| [`ft_lstadd_back`](#ft_lstadd_back) | add a node at the back |
| [`ft_lstsize`](#ft_lstsize) | number of nodes |
| [`ft_lstlast`](#ft_lstlast) | last node |
| [`ft_lstdelone`](#ft_lstdelone) | free one node |
| [`ft_lstclear`](#ft_lstclear) | free the whole list |
| [`ft_lstiter`](#ft_lstiter) | apply a function to each content |
| [`ft_lstmap`](#ft_lstmap) | build a new transformed list |

```c
t_list	*lst;

lst = NULL;
ft_lstadd_back(&lst, ft_lstnew(ft_strdup("a")));
ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
ft_lstclear(&lst, free);   /* frees the strings and the nodes */
```

In this example, a failing `ft_lstnew` returns `NULL`, which `ft_lstadd_back` ignores: the
allocated string is then lost. In real code, check the return value of `ft_lstnew`.

---

### ft_lstnew

```c
t_list	*ft_lstnew(void *content);
```

Allocates a node with `content` as its content and `next` set to `NULL`. The content is not
copied.

**Returns:** the node, or `NULL` if the allocation fails.

---

### ft_lstadd_front

```c
void	ft_lstadd_front(t_list **lst, t_list *new);
```

Adds the node `new` at the front of the list `*lst`. Does nothing if `lst` or `new` is `NULL`.

---

### ft_lstadd_back

```c
void	ft_lstadd_back(t_list **lst, t_list *new);
```

Adds the node `new` at the back of the list `*lst` (or makes it the first node if the list is
empty). Does nothing if `lst` or `new` is `NULL`. Walks the whole list: O(n).

---

### ft_lstsize

```c
int	ft_lstsize(t_list *lst);
```

**Returns:** the number of nodes in `lst` (0 for an empty list).

---

### ft_lstlast

```c
t_list	*ft_lstlast(t_list *lst);
```

**Returns:** the last node of `lst`, or `NULL` if the list is empty.

---

### ft_lstdelone

```c
void	ft_lstdelone(t_list *lst, void (*del)(void *));
```

Frees the node's content with `del`, then the node itself. Does not touch the next node: it is
up to the caller to relink the list. Does nothing if `lst` or `del` is `NULL`.

---

### ft_lstclear

```c
void	ft_lstclear(t_list **lst, void (*del)(void *));
```

Frees every node of `*lst` and its content (with `del`), then sets `*lst` to `NULL`.
Does nothing if `lst` or `del` is `NULL`.

---

### ft_lstiter

```c
void	ft_lstiter(t_list *lst, void (*f)(void *));
```

Calls `f` on the content of each node, from first to last. Does nothing if `f` is `NULL`.

---

### ft_lstmap

```c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

Builds a new list where each content is `f(content)` of the matching node of `lst`.
The original list is not modified.

**Returns:** the new list; `NULL` if `lst` is empty, if `f` or `del` is `NULL`, or if an
allocation fails. In that last case, everything created so far is freed with `del`.
