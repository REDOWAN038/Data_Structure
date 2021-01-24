#include<stdio.h>
int n;
int front = -1;
int rear = -1;
int a[10000];

void enqueue(int);
void dequeue();
void peek();
void display();

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

void enqueue(int val)
{
	if((rear+1)%n==front)
		printf("List is full\n");

	else if(front==-1 && rear==-1)
	{
		printf("%d enqueued successfully\n",val);
		front = rear = 0;
		a[rear] = val;
	}

	else
	{
		printf("%d enqueued successfully\n",val);
		rear = (rear+1)%n;
		a[rear] = val;
	}
}

void dequeue()
{
	if(front==-1 && rear==-1)
		printf("List is empty\n");

	else if(front==rear)
	{
		printf("Dequeued element is : %d\n",a[front]);
		front = rear = -1;
	}

	else
	{
		printf("Dequeued element is : %d\n",a[front]);
		++front;
	}
}

void peek()
{
	if(front==-1 && rear==-1)
		printf("List is empty\n");

	else
		printf("Peek value is : %d\n",a[front]);
}

void display()
{
	if(front==-1 && rear==-1)
        printf("List is empty\n");

    else
    {
        int i = front;

        while(i!=rear)
        {
            printf("%d ",a[i]);
            i = (i+1)%n;
        }

        printf("%d\n",a[rear]);
    }
}