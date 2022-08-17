#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
void push(struct stack *s, int key)
{
    if (s->top == s->size - 1)
    {
    }
    else
    {
        s->arr[++s->top] = key;
    }
}
int pop(struct stack *s)
{
    int x = 0;
    if (s->top == -1)
    {
    }
    else
    {
        x = s->arr[s->top--];
    }
    return x;
}
int main()
{
    struct stack s1;
    scanf("%d", &s1.size);
    s1.top = -1;
    s1.arr = (int *)malloc(s1.size*sizeof(int));
    push(&s1, 5);
    printf("%d", s1.arr[s1.top]);
    int k = pop(&s1);
    printf("\n%d", k);
}