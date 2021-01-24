#include<stdio.h>
#define sz 5
int stack[sz],top=-1;

void push(int element);
int isfull();
int pop();
int isempty();
void peek();
void traverse();
int main()
{
    int ch,item;

    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Traverse\n");
        printf("5.Quit\n");

        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter element : ");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2: item = pop();
                    if(item==0)
                        printf("stack is underflow\n");
                    else
                        printf("popped : %d\n",item);
                    break;
            case 3: peek();
                    break;
            case 4: traverse();
                    break;
            case 5: exit(0);
                    break;
            default : printf("Error\n\n");
        }
    }

    return 0;
}

void push(int element)
{
    if(isfull())
        printf("stack is overflow\n");
    else
    {
        top++;
        stack[top] = element;
        printf("%d pushed\n",element);
    }
}

int isfull()
{
    if(top==sz-1)
        return 1;
    else
        return 0;
}

int pop()
{
    if(isempty())
        return 0;
    else
    {
        return stack[top--];
    }
}

int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void peek()
{
    if(isempty())
        printf("stack is empty\n");
    else
        printf("top element is : %d\n",stack[top]);
}

void traverse()
{
    if(isempty())
        printf("stack is empty\n");
    else
    {
        int i;
        for(i=0;i<=top;i++)
            printf("%d\t",stack[i]);

        printf("\n");
    }
}
