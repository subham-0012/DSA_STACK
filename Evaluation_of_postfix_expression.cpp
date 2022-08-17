#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    int length;
    int top;
    int *arr;
} stack;

void initializeStack(stack *st, int n)
{
    st->length = n;
    st->top = -1;
    st->arr = (int *)malloc(st->length * sizeof(int));
}

int isOperand(char val)
{
    if (val == '+' || val == '-' || val == '/' || val == '*')
        return 0;

    else
        return 1;
}

void push(stack *st, int n)
{
    st->arr[++st->top] = n;
}

int pop(stack *st)
{
    int returnValue;
    returnValue = st->arr[st->top--];
    return returnValue;
}

void evaluate(char *Arr, stack *st)
{
    int i = 0, x1, x2, res = 0;
    while (Arr[i] != '\0')
    {
        if (isOperand(Arr[i]))
        {
            printf("\nThe operand is : %c", Arr[i]);
            push(st, Arr[i] - '0');
        }

        else
        {
            printf("\nThe operand is : %c", Arr[i]);
            x2 = pop(st);
            printf("\nthe popped element is %d ", x2);
            x1 = pop(st);
            printf("\nthe popped element is %d \n", x1);
            switch (Arr[i])
            {
            case '+':
                res = x1 + x2;
                printf("the result is %d \n", res);
                push(st, res);
                // st->arr[++st->top] = res;
                break;
            case '-':
                res = x1 - x2;
                printf("the result is %d \n", res);
                push(st, res);
                // st->arr[++st->top] = res;
                break;
            case '*':
                res = x1 * x2;
                printf("the result is %d \n", res);
                push(st, res);
                // st->arr[++st->top] = res;
                break;
            case '/':
                res = x1 / x2;
                printf("the result is %d \n", res);
                push(st, res);
                // st->arr[++st->top] = res;
                break;
            default:
                printf("Error");
                return;
            }
        }
        i++;
    }
    printf("\nThe answer is : %d", res);
}

int main()
{
    stack st;
    int n;
    printf("Enter the length : ");
    scanf("%d", &n);
    initializeStack(&st, n);
    char ar[20];
    printf("Enter the postfix expression : ");
    scanf("%s", ar);
    evaluate(ar, &st);
    return 0;
}