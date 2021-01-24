#include<stdio.h>
#include<malloc.h>

struct node{

	int val;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int);
void dequeue();
void display();
void peek();

int main()
{
	int c,val;

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
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->val = val;
	newnode->next = NULL;

	printf("%d is enqueued succcessfully\n",val);

	if(rear==NULL)
	{
		front = rear = newnode;
		rear->next = front;
	}

	else
	{
		rear->next = newnode;
		rear = newnode;
		rear->next = front;
	}
}

void dequeue()
{
	if(front==NULL && rear==NULL)
		printf("List is empty\n");

	else if(front==rear)
	{
		printf("%d is dequeued\n",front->val);
		front = rear = NULL;
	}

	else
	{
		struct node *temp;
		temp = front;
		front = front->next;
		rear->next = front;
		printf("%d is dequeued\n",temp->val);
		free(temp);
	}
}

void peek()
{
	if(front==NULL && rear==NULL)
		printf("List is empty\n");
	else
		printf("Peek value is : %d\n",front->val);
}

void display()
{
	if(front==NULL && rear==NULL)
		printf("List is empty\n");
	else
	{
		struct node *temp = front;

		while(temp!=rear)
		{
			printf("%d ",temp->val);
			temp = temp->next;
		}

		printf("%d\n",temp->val);
	}
}