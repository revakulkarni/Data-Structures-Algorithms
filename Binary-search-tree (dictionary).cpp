// PROBLEM STATEMENTS

/*Assignment 6 : A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. 
				Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. 
				Use Binary Search Tree for implementation.
*/
// CODE 
#include<iostream>
#include<string.h>
using namespace std;
typedef struct node{
	char k[20];
	char m[20];
	class node *left;
	class node *right;
}node;
class dict{
	public:
	node *root;
	void create();
	void disp(node *);
	void insert(node *root,node *temp);
	int search(node *,char []);
 	int update(node *,char []);
	node* del(node *,char []);
 	node * min(node *);
};

void dict :: create(){
	class node *temp;
	int ch;
	do{
		temp = new node;
		cout<<"\nEnter keyword : ";
		cin>>temp->k;
		cout<<"\nEnter meaning : ";
		cin>>temp->m;
		temp->left = NULL;
		temp->right = NULL;
		if(root == NULL){
			root = temp;
		}
		else{
			insert(root,temp);
		}
		cout<<"\n Do you want to add more entries? (y=1/n=0) : ";
		cin>>ch;
	}
	while(ch==1);
}
void dict :: insert(node *root,node *temp){
	if(strcmp(temp->k,root->k) < 0){
		if(root->left == NULL)
			root->left =temp;
		else
			insert(root->left,temp);
	}	
	else{
		if(root->right == NULL)
			root->right = temp;
		else
			insert(root -> right,temp);
	}
}

void dict:: disp(node * root){
	if( root != NULL){
		disp(root->left);
	 	cout<<"\n Key Word :"<<root->k;
		cout<<"\t Meaning :"<<root->m;
		disp(root->right);
	}
}

int dict :: search(node * root,char k[20]){
	int c = 0;
	while(root != NULL){
		c++;
		if(strcmp(k,root -> k )==0){
			cout<<"\nNo of Comparisons : "<<c;
			return 1;
		}
		if(strcmp (k, root->k) < 0)
   			root = root->left;
        if(strcmp (k, root->k) > 0)
   			root = root->right;
	}
	return -1;
}

int dict :: update(node * root ,char k  [20]){
	while(root != NULL){
  		if(strcmp (k,root->k) == 0){
   			cout<<"\nEnter New Meaning of the Keyword  : ";
   			cin>>root->m;
   			return 1;
  		}
  	if(strcmp (k, root->k) < 0)
   		root = root->left;
  	if(strcmp (k, root->k) > 0)
   		root = root->right;
 	}
	return -1;
}

node* dict :: del(node * root,char k[20]){
 	node *temp;

 	if(root == NULL){
  		cout<<"\nElement No Found";
  		return root;
 	}

	if (strcmp(k,root->k) < 0){
  		root->left = del(root->left, k);
  		return root;
 	}
 	if (strcmp(k,root->k) > 0){
   		root->right = del(root->right, k);
   		return root;
 	}

 	if (root->right==NULL&&root->left==NULL){
  		temp = root;
  		delete temp;
  		return NULL;
  	}
  	if(root->right==NULL){
  		temp = root;
  		root = root->left;
  		delete temp;
  		return root;
  	}
  	else if(root->left==NULL){
  		temp = root;
  		root = root->right;
  		delete temp;
  		return root;
  	}
	temp = min(root->right);
  	strcpy(root->k,temp->k);
  	root->right = del(root->right, temp->k);
  	return root;
}

node * dict :: min(node *q){
 	while(q->left != NULL){
  	q = q->left;
 	}
 	return q;
}

int main(){
	int ch;
	dict d;
	d.root = NULL;
	do{
		cout<<"\t\nMenu\n1.Create\n2.Display\n3.Search\n4.Update\n5.Delete\nEnter Your choice : ";
		cin>>ch;
		switch(ch){
			case 1: d.create();
				break;
			case 2: if(d.root==NULL){
					cout<<"\nNo any Keyword";
				}
				else{
					d.disp(d.root);
				}
				break;
			case 3: if(d.root == NULL){
						cout<<"\nDictionary is Empty. First add keywords then try again ";
					}
					else{
						cout<<"\nEnter Keyword which u want to search:";
						char k[20];
						cin>>k;
						if( d.search(d.root,k) == 1)
							cout<<"\nKeyword Found";
						else
							cout<<"\nKeyword Not Found";
					}
					break;
			case 4:if(d.root == NULL){
  						cout<<"\nDictionary is Empty. First add keywords then try again ";
 					}
  					else{
  						cout<<"\nEnter Keyword which meaning  want to update:";
  						char k[20];
  						cin>>k;
  						if(d.update(d.root,k) == 1)
  							cout<<"\nMeaning Updated";
  						else
  							cout<<"\nMeaning Not Found";
  					}
  					break;
			case 5:if(d.root == NULL){
  						cout<<"\nDictionary is Empty. First add keywords then try again ";
					}
 					else{
  						cout<<"\nEnter Keyword which u want to delete:";
  						char k[20];
  						cin>>k;
  						if(d.root == NULL){
  							cout<<"\nNo any Keyword";
						}
  						else{
  							d.root = d.del(d.root,k);
						}
   					}
		}
	}
	while(ch<=5);
	return 0;
}
// OUTPUT
/*
	***** Telephone (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 1

	Enter a Telephone No: 111

	Enter a Client Name: aaa

	..... Do You Want to Insert More Key y/n :y

	Enter a Telephone No: 222

	Enter a Client Name: bbb

	..... Do You Want to Insert More Key y/n :y

	Enter a Telephone No: 333

	Enter a Client Name: ccc

	..... Do You Want to Insert More Key y/n :y

	Enter a Telephone No: 666

	Enter a Client Name: fff

	..... Do You Want to Insert More Key y/n :y

	Enter a Telephone No: 999

	Enter a Client Name: zzz

	..... Do You Want to Insert More Key y/n :n

	..... Do You Want to Continue in Main Menu:y/n y

	***** Telephone (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 2

		Key		Name
	h[0]	-1		NULL
	h[1]	111		aaa
	h[2]	222		bbb
	h[3]	333		ccc
	h[4]	-1		NULL
	h[5]	-1		NULL
	h[6]	666		fff
	h[7]	-1		NULL
	h[8]	-1		NULL
	h[9]	999		zzz
	..... Do You Want to Continue in Main Menu:y/n y

	***** Telephone (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 3

	Enter a Key Which You Want to Search: 666

	666 is Found at 6 Location With Name fff
	..... Do You Want to Continue in Main Menu:y/n y

	***** Telephone (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 4

	Enter a Key Which You Want to Delete: 111

	111 is Found at 1 Location With Name aaa
	Key is Deleted
	..... Do You Want to Continue in Main Menu:y/n y

	***** Telephone (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 2

		Key		Name
	h[0]	-1		NULL
	h[1]	-1		NULL
	h[2]	222		bbb
	h[3]	333		ccc
	h[4]	-1		NULL
	h[5]	-1		NULL
	h[6]	666		fff
	h[7]	-1		NULL
	h[8]	-1		NULL
	h[9]	999		zzz
	..... Do You Want to Continue in Main Menu:y/n 
y

	***** Telephone (ADT) *****
	1. Insert
	2. Display
	3. Find
	4. Delete
	5. Exit
	..... Enter Your Choice: 5

	..... Do You Want to Continue in Main Menu:y/n n

*/
