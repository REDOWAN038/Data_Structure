#include<stdio.h>
int deque[1000];
int front=-1,rear=-1;
int n;

void enqueuefront(int);
void enqueuerear(int);
void dequeuefront();
void dequeuerear();
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
        printf("1. EnqueueFront\n");
        printf("2. EnqueueRear\n");
        printf("3. DequeueFront\n");
        printf("4. DequeueRear\n");
        printf("5. Peek\n");
        printf("6. Display\n");
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
            enqueuefront(val);
        }

        else if(c==2)
        {
            printf("Enter value : ");
            scanf("%d",&val);
            printf("\n");
            enqueuerear(val);
        }

        else if(c==3)
            dequeuefront();

        else if(c==4)
            dequeuerear();

        else if(c==5)
            peek();

        else if(c==6)
            display();

        else
            return 0;
    }
}

void enqueuefront(int val)
{
	if((rear+1)%n==front)
		printf("List is full\n");

	else if(front==-1 && rear==-1)
	{
		printf("%d is enqueued successfully\n",val);
		front = rear = 0;
		deque[front] = val;
	}

	else
	{
		--front;
		front = (front+n)%n;
		deque[front] = val;
	}
}

void enqueuerear(int val)
{
	if((rear+1)%n==front)
		printf("List is full\n");

	else if(front==-1 && rear==-1)
	{
		printf("%d is enqueued successfully\n",val);
		front = rear = 0;
		deque[rear] = val;
	}

	else
	{
	    printf("%d is enqueued successfully\n",val);
		rear = (rear+1)%n;
		deque[rear] = val;
	}
}

void dequeuefront()
{
	if(front==-1 && rear==-1)
		printf("List is empty\n");
	else if(front==0 && rear==0)
	{
		printf("%d is dequeued successfully\n",deque[front]);
		front = rear = -1;
	}

	else if(front==rear)
	{
		printf("%d is dequeued successfully\n",deque[front]);
		front = rear = -1;
	}

	else
	{
		printf("%d is dequeued successfully\n",deque[front]);
		front = (front+1)%n;
	}
}

void dequeuerear()
{
	if(front==-1 && rear==-1)
		printf("List is empty\n");

	else if(front==0 && rear==0)
	{
		printf("%d is dequeued successfully\n",deque[front]);
		front = rear = -1;
	}

	else if(front==rear)
	{
		printf("%d is dequeued successfully\n",deque[front]);
		front = rear = -1;
	}

	else
	{
		printf("%d is dequeued successfully\n",deque[rear]);
		--rear;
		rear = (rear+n)%n;
	}
}

void peek()
{
	if(front==-1 && rear==-1)
		printf("List is empty\n");

	else
		printf("Peek value is : %d\n",deque[front]);
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
            printf("%d ",deque[i]);
            i = (i+1)%n;
        }

        printf("%d\n",deque[rear]);
    }
}
