
// 1.Given binary string str of size N the task is to check if the given string is valid or not. A
// string is called valid if the number of 0's equals the number of 1's and at any moment starting
// from the left of the string number 0's must be greater than or equals to the number of 1's.
//Time Complexity is O(t*n) and Space Complexity is O(n)
#include <stdio.h>
#include <stdlib.h>
//creating stack stucture
struct stack
{
    int top;
    int size;
    char *arr;
};
void push(struct stack *s, char key)//push function
{
    if (s->top == s->size - 1)//checking is stack is already full
    {
        printf("Stack is full");
    }
    else
    {
        s->arr[++s->top] = key;//pushing the element after incrementing the top
    }
}   
char pop(struct stack *s)//pop function
{
    char x=1;
    if (s->top == -1)//checking if stack is already empty
    {
        x=0;//assigning x as 0
    }
    else
    {
        s->arr[s->top--];//assigning x as value of top and decrementing the top
    }
    return x;//returning x
}
int main()
{
    char character;
    int test;
    printf("enter the number of test cases ");
    scanf("%d",&test);//scanning the number of test cases
    while(test--)
    {
        struct stack s1;//creating object of struct stack type
        int isValid = 1;//declaring a variable to check validity
        printf("enter the size of string ");
        scanf("%d", &s1.size);//taking the size of string
        s1.top = -1;//assigning the top as -1
        s1.arr = (char *)malloc(s1.size * sizeof(char));//dynamically allocating the memory for array
        for (int i = 0; i < s1.size; i++)
        {
            if (isValid)//checking if string is valid or not everytime
            {
                scanf(" %c", &character); //checking if character is 0
                if (character == '0')
                {
                    push(&s1, character);//pushing if character is 0
                }
                else
                {
                    isValid = pop(&s1);//popping the character and assigning it to x
                }
            }
        }
        if(isValid&&s1.top==-1)//checking if string is valid and empty also
        {
            printf("yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
