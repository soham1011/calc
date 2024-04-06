#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// push
// pop
//  isempty
//  top

typedef struct
{
    char items[10];
    int size;
} Stack;

bool IsEmpty(Stack *s)
{
    return (s->size <= 0);
}

void Push(Stack *s, char c)
{
    if (s->size >= 10)
    {
        return;
    }
    s->items[s->size] = c;
    s->size++;
}

char Pop(Stack *s)
{
    if (IsEmpty)
    {
        return 'P';
    }
    char c = s->items[s->size - 1];
    s->size--;
    s->items[s->size] = '\0';
    return c;
}



char Top(Stack *s)
{
    return s->items[s->size - 1];
}

Stack *CreateStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->size = 0;
    return s;
}

int main(){
    
    Stack *s = CreateStack();
    Push(s, '+');
    Push(s, 'h');
    printf("%c", Top(s));
    Push(s, 'k');
    Push(s, '9');
    Push(s, '/');
    printf("%c", Pop(s));
    printf("%c", Top(s));







    return 0;
}