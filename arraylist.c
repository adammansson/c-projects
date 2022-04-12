#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int *arr;
    int allocated;
    int length;
} ArrayList;

ArrayList *create_al(void)
{
    ArrayList *new_al;
    new_al = malloc(sizeof(ArrayList));
    new_al->allocated = 10;
    new_al->arr = malloc(sizeof(int) * new_al->allocated);
    new_al->length = 0;

    return new_al;
}

int get_al(ArrayList *ptr, int index)
{
    return *(ptr->arr + index);
}

void add_al(ArrayList *ptr, int element)
{
    // Reallocate if the array is getting filled up
    if ((ptr->allocated - ptr->length) <= 3)
    {
        ptr->allocated = 2 * ptr->allocated;
        ptr->arr = realloc(ptr->arr, sizeof(int) * ptr->allocated);
    }
    *(ptr->arr + ptr->length) = element;
    ptr->length = ptr->length + 1;
}

int main(void)
{
    ArrayList *my_al = create_al();
    for (int i = 0; i < 100; i++)
    {
        add_al(my_al, i);
        printf("%i, %i\n", i, my_al->allocated;
    }

    for (int i = 0; i < my_al->length; i++)
    {
        printf("%d\n", get_al(my_al, i));
    }

    return 0;
}

