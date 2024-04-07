
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

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
    if (IsEmpty(s))
    {
        return '\0';
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
    s->size = 0;// int main()          


    return s;
}

size_t getSize(const char *s)
{
    size_t size = 0;

    while (*s++)
        ++size;

    return size;
}

bool isGreaterPres(char s, char c)
{
    if (s == c || (s == '-' && c == '+') || (s == '+' && c == '-'))
    {
        return true;
    }
    else if (s == '*' || s == '/')
    {
        return true;
    }
    return false;
}

char *ToPostFix(char *inp)
{
    Stack *s = CreateStack();
    char *postfix = malloc((getSize(inp) + 1) * sizeof(char));

    int postfixIndex = 0;

    for (int i = 0; i < getSize(inp); i++)
    {
        if (inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/')
        {
            if (IsEmpty(s))
            {
                Push(s, inp[i]);
            }
            else
            {
                while (!IsEmpty(s) && isGreaterPres(Top(s), inp[i]))
                {
                    postfix[postfixIndex++] = Pop(s);
                }
                Push(s, inp[i]);
            }
        }
        else
        {
            postfix[postfixIndex++] = inp[i];
        }
    }

    while (!IsEmpty(s))
    {
        postfix[postfixIndex++] = Pop(s);
    }

    postfix[postfixIndex] = '\0'; 
    return postfix;
}


int main() {
    char *inp = "1+5/2*3";
    char *uwu = ToPostFix(inp);
    Stack *s2 = CreateStack();

    for (int i = 0; i < getSize(uwu); i++) {
        if (isdigit(uwu[i])) {
            Push(s2, uwu[i]);
        } else if (uwu[i] == '+' || uwu[i] == '-' || uwu[i] == '*' || uwu[i] == '/') {
            char x = Pop(s2);
            char y = Pop(s2);
            int digit_x = x - '0';
            int digit_y = y - '0';
            int result;

            if (uwu[i] == '+') {
                result = digit_y + digit_x;
            } else if (uwu[i] == '-') {
                result = digit_y - digit_x;
            } else if (uwu[i] == '*') {
                result = digit_y * digit_x;
            } else if (uwu[i] == '/') {
                result = digit_y / digit_x;
            }

            char z = result + '0';
            Push(s2, z);
        }
    }

    
    char final_result = Pop(s2);
    printf("Result: %c\n", final_result);

    
    free(uwu);

    return 0;
}
