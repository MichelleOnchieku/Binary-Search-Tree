#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left, *right;
	
};

//GENERATE A NEW NODE
node *insert(node *root, int item)
{
	//for the first time
	if(root==NULL)
	{
		//new node generated
		node *newnode = new node;
		newnode->data = item;//data part will have item
		newnode->left = NULL;//left assigned to NULL
		newnode->right = NULL;//right assigned to NULL
		return newnode;
	}
	//not null
	if(item < root->data)//if item is less than root
	{
		//move to left carrying item
		root->left = insert(root->left, item);
	}
	else
	{
		//move to right carrying item
		root->right = insert(root->right, item);
	}
	return root;
}

//PREORDER TRAVASALS
void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		//processs data, left , then right
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

//INORDER TRAVASALS
void inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		//move to left, data, then right
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

//POSTORDER TRAVASALS
void postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		//move to left, right, then data
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}


//SEARCHING
void search(node *root, int item)
{
	//nothing in tree
	if(root==NULL)
	{
		return;
	}
	//if item matches search value
	else if(item==root->data)
	{
		cout<<"Found it!";
	}
	//less than value on the right we continue moving
	else if(item < root->data)
	{
		//continue moving holding the value
		search(root->left ,item);
	}
	else
	{
		search(root->right, item);
	}
}

int main()
{
	node *root = NULL;
	int i, n, item;
	cout<<"How many items: ";
	cin>>n;
	cout<<"Enter values: ";
	for(i=0;i<n;i++)
	{
		cin>>item;
		root = insert(root, item);
	}
	cout<<"\nPre-order Travasal: ";
	preorder(root);
	cout<<"\nIn-order Travasal: ";
	inorder(root);
	cout<<"\nPost-order Travasal: ";
	postorder(root);
	
	cout<<"\nEnter search key: ";
	cin>>item;
	search(root, item);
}