#include <stdio.h>
#include <stdlib.h>
int total_price=0;
struct Books
{
    char Title[50];
    char author[50];
    char publisher[50];
    int year_of_publication,ISBN,price;
};
struct Node
{
    struct Node *prev;
    struct Books book;
    struct Node *Next;
};
struct stack
{
    int size;
    int top;
    struct Node *book;
};
void push(struct stack *stk)
{
    if(stk->top<stk->size-1)
    {
        struct Node *ptr = stk->book, *t;
        if (stk->book == NULL)
        {
            stk->book = (struct Node *)malloc(sizeof(struct Node));
            stk->book->Next = NULL;
            stk->book->prev = NULL;
            printf("enter the Name of Book ");
            scanf("%s", stk->book->book.Title);
            printf("enter the author Name of Book ");
            scanf("%s", stk->book->book.author);
            printf("enter the publisher Name of Book ");
            scanf("%s", stk->book->book.publisher);
            printf("enter the year of publication of Book ");
            scanf("%d", &stk->book->book.year_of_publication);
            printf("enter the ISBN number of Book ");
            scanf("%d", &stk->book->book.ISBN);
            printf("enter the price of Book ");
            scanf("%d", &stk->book->book.price);
            total_price+=stk->book->book.price;
            ptr = stk->book;
        }
        else
        {
            while (ptr->Next != NULL)
            {
                ptr = ptr->Next;
            }
            t = (struct Node *)malloc(sizeof(struct Node));
            t->Next = NULL;
            t->prev = NULL;
            printf("enter the Name of Book ");
            scanf("%s", t->book.Title);
            printf("enter the author Name of Book ");
            scanf("%s", t->book.author);
            printf("enter the publisher Name of Book ");
            scanf("%s", t->book.publisher);
            printf("enter the year of publication of Book ");
            scanf("%d", &t->book.year_of_publication);
            printf("enter the ISBN number of Book ");
            scanf("%d", &t->book.ISBN);
            printf("enter the price of Book ");
            scanf("%d", &t->book.price);
            total_price+=t->book.price;
            t->Next = NULL;
            t->prev = ptr;
            ptr = t;
            stk->book=ptr;
        }
        stk->top++;
    }
}
void pop(struct stack *stk)
{
    struct Node *ptr = stk->book;
    if(stk->top>-1)
    {
        while (stk->top!=-1)
        {
            printf("\nThe Book name is %s\n", stk->book->book.Title);
            printf("The Book author is %s\n", stk->book->book.author);
            printf("The Book publisher is %s\n", stk->book->book.publisher);
            printf("The year of publication of book is %d\n", stk->book->book.year_of_publication);
            printf("The ISBN number of book is %d\n", stk->book->book.ISBN);
            printf("The price of book is is %d\n", stk->book->book.price);
            stk->book = stk->book->prev;
            stk->top--;
        }
    }
}
int main()
{
    struct stack stk;
    stk.top=-1;
    stk.book= NULL;
    printf("Enter the size of stack ");
    scanf("%d",&stk.size);
    for(int i=0;i<stk.size;i++)
    {
        push(&stk);
    }
    pop(&stk);
    printf("The total price of books is %d",total_price);
    return 0;
}