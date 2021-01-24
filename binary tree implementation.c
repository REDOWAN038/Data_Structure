#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left,*right;
};

struct node* create(int x)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	int y;

	if(x==-1)
		return NULL;

	newnode->data = x;
	printf("\nEnter left child %d (-1 for no child): ",x);
	scanf("%d",&y);
	newnode->left = create(y);
	printf("\nEnter right child %d (-1 for no child): ",x);
	scanf("%d",&y);
	newnode->right = create(y);

	return newnode;
}

void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main()
{
	struct node *root;
	root = NULL;
	int x;
	printf("Enter root (-1 for no root) : ");
	scanf("%d",&x);
	root = create(x);

	printf("Preorder is : ");
	preorder(root);
	printf("\n");

	printf("Inorder is : ");
	inorder(root);
	printf("\n");

	printf("Postorder is : ");
	postorder(root);
	printf("\n");
}
