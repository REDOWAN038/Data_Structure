#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *left,*right;

	node(int x)
	{
		val = x;
		left = right = NULL;
	}
};

node* insert(node *root,int x)
{
	if(root==NULL)
	{
		root = new node(x);
		return root;
	}

	else if(x<root->val)
		root->left = insert(root->left,x);

	else
		root->right = insert(root->right,x);

	return root;
}

void traverse(node *root)
{
	if(root==NULL)
		return;

	traverse(root->left);
	cout<<root->val<<endl;
	traverse(root->right);
}

bool search(node *root,int x)
{
	if(root==NULL)
		return false;
	else if(root->val==x)
		return true;
	else if(x<root->val)
		return search(root->left,x);
	else
		return search(root->right,x);
}

node* findmin(node *root)
{
	while(root!=NULL && root->left!=NULL)
		root = root->left;
	return root;
}

node* deletee(node *root,int x)
{
	if(root==NULL)
		return root;

	else if(x<root->val)
		root->left = deletee(root->left,x);

	else if(x>root->val)
		root->right = deletee(root->right,x);

	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root = NULL;
			return root;
		}

		else if(root->left==NULL)
		{
			node *temp = root;
			root = root->right;
			delete temp;
			return root;
		}

		else if(root->right==NULL)
		{
			node *temp = root;
			root = root->left;
			delete temp;
			return root;
		}

		else
		{
			node *temp = findmin(root->right);
			root->val = temp->val;
			root->right = deletee(root->right,temp->val);
			return root;
		}
	}
}

int main()
{
	node *root = NULL;
	int n,i,x,q;

	cout<<"Enter how many numbers : ";
	cin>>n;

	cout<<"enter numbers : ";

	for(i=0;i<n;i++)
	{
		cin>>x;
		root = insert(root,x);
	}

	traverse(root);

	cout<<"enter how many search query : ";
	cin>>q;

	for(i=0;i<q;i++)
	{
	    cout<<"enter value to search : ";
		cin>>x;
		if(search(root,x))
			cout<<"found\n";
		else
			cout<<"not found\n";
	}

	cout<<"enter how many delete query : ";
	cin>>q;

	for(i=0;i<q;i++)
	{
		cin>>x;

		if(search(root,x))
		{
			root = deletee(root,x);
			cout<<x<<" is deleted successfully\n";
		}

		else
			cout<<x<<" is not in the tree\n";
	}

	traverse(root);

	return 0;
}
