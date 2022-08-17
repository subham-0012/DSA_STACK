// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if
// the input string is valid.
// An input string is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
//Time complexity is O(n) and Space complexity is O(n)
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
    char x;
    if (s->top == -1)//checking if stack is already empty
    {
        x=0;//assigning x as 0
    }
    else
    {
        x=s->arr[s->top--];//assigning x as value of top and decrementing the top
    }
    return x;//returning x
}
int main()
{
    char character,result;
    struct stack s1;  //creating object of struct stack type
    int isValid = 1;  //declaring a variable to check validity
    printf("enter the size of string ");
    scanf("%d", &s1.size);                           //taking the size of string
    s1.top = -1;                                     //assigning the top as -1
    s1.arr = (char *)malloc(s1.size * sizeof(char)); //dynamically allocating the memory for array
    for (int i = 0; i < s1.size; i++)
    {
        if (isValid) //checking everytime if string is valid or not
        {
            scanf(" %c", &character); //scanning the character
            if (character == '(' || character == '{' || character == '[')//checking if character is an opening bracket
            {
                push(&s1, character); //pushing if character is an opening bracket
            }
            else if (character == ')' || character == '}' || character == ']')//checking if character is an closing bracket
            {
                result = pop(&s1); //popping the character and assigning it to x
                if ((result == '(' && character == ')') || (result == '{' && character == '}') || (result == '[' && character == ']'))//checking if the brackets are correct
                {
                    isValid = 1;
                }
                else
                {
                    isValid = 0;
                }
            }
        }
    }
    if (isValid && s1.top == -1) //checking if string is valid and empty also
    {
        printf("yes\n");
    }
    else
    {
        printf("No\n");
    }
}