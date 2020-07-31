#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct node
 {
 	int info;
 	struct node *left,*right;
 }*root=NULL;

 void CreateBST(int item)
 {
 	struct node* newnode;
 	newnode=(struct node*) malloc(sizeof(struct node*));
 	newnode->info=item;
 	newnode->left=newnode->right;
 	if(root==NULL)
 	{
 		root=newnode;
 		return;
 	}
 	struct node* parent=NULL;
 	struct node* current=root;
 	while(current!=NULL)
 	{
 		parent=current;
 		if(item<=current->info)
 			current=current->left;
 		else
 			current=current->right;
 	}
 		if (item<=parent->info)
 		{
 			parent->left=newnode;
 		}
 		else
 			parent->right=newnode;
 		return;

 } 
 void inorder(struct node *root)
 {
 	if(root!=NULL)
 	{
 		inorder(root->left);
 		printf("%d\n",root->info );
 		inorder(root->right);
 	}
 }
int main()
{
	int item,choice;
	while(choice!=3)
	{
	printf("Enter 1 for insertion 2 for inorder\n");
	scanf("%d",&choice);
		switch(choice)
		{
		case 1:
		printf("Enter element you wanna enter\n");
		scanf("%d",&item);
		CreateBST(item);
		break;
		case 2:
		printf("Inorder is\n");
		inorder(root);
		break;
		}
	}
}