#include<stdio.h>
int n;
int top1=-1,top2=-1;
int count=0;
int s1[1000],s2[1000];

void enqueue(int);
void dequeue();
void peek();
void display();
void push1();
int pop1();
void push2();
int pop2();

int main()
{
    int c,val;
    printf("Enter number of elements of the queue : ");
    fflush(stdin);
    scanf("%d",&n);

    while(1)
    {
        printf("\nYour choices: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice : ");
        fflush(stdin);
        scanf("%d",&c);
        printf("\n");

        if(c==1)
        {
            printf("Enter value : ");
            scanf("%d",&val);
            printf("\n");
            enqueue(val);
        }

        else if(c==2)
            dequeue();

        else if(c==3)
            peek();

        else if(c==4)
            display();

        else
            return 0;
    }
}

void push1(int val)
{

    s1[++top1] = val;
    count++;

}

int pop1()
{
    return s1[top1--];
}

void push2(int val)
{
    s2[++top2] = val;
}

int pop2()
{
    count--;
    return s2[top2--];
}

void enqueue(int val)
{
    if(top1==(n-1))
        printf("List is full\n");
    else
    {
        printf("%d is enqueued successfully\n",val);
        push1(val);
    }
}

void dequeue()
{
    if(top1==-1 && top2==-1)
        printf("List is empty\n");
    else
    {
        int i;
        for(i=0; i<count; i++)
            push2(pop1());

        printf("%d is dequeud successfully\n",pop2());

        for(i=0; i<count; i++)
            push1(pop2());
    }
}

void peek()
{
    if(top1==-1)
        printf("List is empty\n");
    else
        printf("Peek value is : %d\n",s1[0]);
}

void display()
{
    if(top1==-1 && top2==-1)
        printf("List is empty\n");

    else
    {
        int i;

        for(i=0; i<=top1; i++)
            printf("%d ",s1[i]);
        printf("\n");
    }
}
