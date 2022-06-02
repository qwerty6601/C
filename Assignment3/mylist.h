#ifndef _MYLIST_H_
#define _MYLIST_H_

/*
* A node in a linked list.
*/
struct Node {
    void *data;
    struct Node *next;
};

/*
* A linked list.
* 'head' points to the first node in the list.
*/
struct List {
    struct Node *head;
};

/*
* Initialize an empty list.
*/
static inline void initList(struct List *list)
{
    list->head = 0;
}

struct Node *addFront(struct List *list, void *data);

/*
* Traverse the list, calling f() with each data item.
*/
void traverseList(struct List *list, void (*f)(void *));

struct Node *findNode(struct List *list, const void *dataSought,
                      int (*compar)(const void *, const void *));

/*
* Flip the sign of the double value pointed to by 'data' by
* multiplying -1 to it and putting the result back into the memory
* location.
*/
void flipSignDouble(void *data);

/*
* Compare two double values pointed to by the two pointers.
* Return 0 if they are the same value, 1 otherwise.
*/
int compareDouble(const void *data1, const void *data2);

/*
* Returns 1 if the list is empty, 0 otherwise.
*/
static inline int isEmptyList(struct List *list)
{
    return (list->head == 0);
}

void *popFront(struct List *list);

/*
* Remove all nodes from the list, deallocating the memory for the
* nodes. You can implement this function using popFront().
*/
void removeAllNodes(struct List *list);

struct Node *addAfter(struct List *list,
                      struct Node *prevNode, void *data);

void reverseList(struct List *list);

#endif /* #ifndef _MYLIST_H_ */