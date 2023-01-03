/*
Problem: telephone book database of N clients. 
Make use of hash table implementation to quickly look up client's telephone number. 
Make use of two collision handling techniques and compare them using number of
comparisons required to find a set of telephone numbers.
*/

#include<iostream>
#include <cstring>
using namespace std;


class hashtable
{
	typedef struct client
	{
	long int key;
	char name[20];

	}client;//end of structure 	
	client h[10];
	public:
		hashtable();	//constructor	
		void Quadratic_Probing();
		void Linear_Probing();
		void display();
		void search(int);
		void del(int);
		int hash(long int);
};//end of class

hashtable::hashtable()	//constructor
{
	for(int i=0;i<10;i++)
	{
		h[i].key=-1;
		strcpy(h[i].name,"NULL");
	}
}		


void hashtable::Quadratic_Probing()
{
	int hi;
	long k;
	char cAns, n[10];
	int flag=0;
	int count=0;
	do
	{
		cout<<"\n Enter Phone Number:";
		cin>>k;
		cout<<"\nEnter name:";
		cin>>n;
		hi=hash(k);
	
		if(h[hi].key==-1)
		{
			h[hi].key=k;
			strcpy(h[hi].name,n);
		}
		else
		{
			for(int i=0;i<10;i++)
			{
				int q_hi=(hi+i*i)%10;
				
				if(h[q_hi].key==-1)
				{
					h[q_hi].key=k;
					strcpy(h[q_hi].name,n);
					count++;
					break;
				}
			}
		}
		cout<<"\n Add More:";
		cin>>cAns;
	}while(cAns=='y' || cAns=='Y');	
	cout<<"Total number of comparisons: "<<count;
}//end  of insert

void hashtable::Linear_Probing()
{
	int hi;
	long k;
	char cAns,n[20];
	int flag=0;
	int count=0;
	do
	{
		cout<<"\n Enter Phone Number:";
		cin>>k;
		cout<<"\nEnter name:";
		cin>>n;
		hi=hash(k);
	
		if(h[hi].key==-1)
		{
			h[hi].key=k;
			strcpy(h[hi].name,n);
		}
		else
		{
			for (int i = hi + 1; i < 10; i++){
			  		if (h[i].key == -1){
			      			h[i].key=k;
							strcpy(h[i].name,n);
							count++;
			      			flag = 1;
			      			break;
			    		}
				}
		      		for (int i = 0; i < hi && flag == 0; i++){
			  		if (h[i].key == -1){
						  count++;
			    	  		h[i].key=k;
							strcpy(h[i].name,n);
			    	  		break;
			    		}
				}
		}
		cout<<"\n Add More:";
		cin>>cAns;
	}while(cAns=='y' || cAns=='Y');	
	cout<<" Total Number of comparisons:"<<count;
}//end  of insert


int hashtable::hash(long int key)
{
	return(key%10);
}//end of hash

void hashtable::display()
{
	cout<<"------------------------------------";
	cout<<"\nSrno\tPhone number\t\tName\n";
	cout<<"------------------------------------\n";
	for(int i=0;i<10;i++)
	{
		cout<<i<<"\t"<<h[i].key<<"\t\t"<<h[i].name<<endl;
	}
	cout<<"------------------------------------\n";
}//end of display

void hashtable::search(int k)
{
	int iFlag=0; 
	cout<<"Enter Phone number to be searched:";
	cin>>k;
	for(int i=0;i<10;i++)
	{
		if(h[i].key==k)
		{
			cout<<"\n Phone Number Found at position "<<i;
			iFlag=1;
		}
	}
	if(iFlag==0)
	cout<<"\n Phone Number Not Found";
}//end of search

void hashtable::del(int s)
{
	int flag=0;
	cout<<"\n Enter phone number to be deleted:";
	cin>>s;
	for(int i=0;i<10;i++)
	{
		if(h[i].key==s)
		{
			
			h[i].key=0;
			cout<<"\n Phone number found and deleted";
			flag=1;
		}
	}
	if(flag==0)
	cout<<"\n Phone number not found";

}//end of del	

int main()
{
	int y,s,iCh;
	hashtable h;
	do
	{
		cout<<"\n---------------LIST---------------\n";
		cout<<"\n1.INSERT (LP)\n2. INSERT (QP) \n3.DISPLAY\n4.SEARCH\n5.DELETE\n6.EXIT\n\n";
		cout<<"Enter your choice:";
		cin>>iCh;
		cout<<"\n";
		
		switch(iCh)
		{
			case 1://insert linear probing
				h.Linear_Probing();
				cout<<"\n";
				break;

			case 2://insert quadratic probing
				h.Quadratic_Probing();
				cout<<"\n";
				break;
				
			case 3://display
				h.display();
				cout<<"\n";
				break;
				
			case 4://search					
				h.search(y);
				cout<<"\n";
				break;
				
			case 5://delete
				h.del(s);
				cout<<"\n";
				break;
				
			case 6://exit
				break;
		}//end of switch
	}while(iCh!=6);//end of do							
return 0;
}