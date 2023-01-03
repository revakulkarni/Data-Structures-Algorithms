#include<iostream>
using namespace std;

int q[20],front=-1,rear=-1,a[20][20],vis[20];

void add(int item)
{
    if(rear==19)
        {cout<<"QUEUE FULL"<<endl;}
            else
            {
                if(rear==-1)
                {
                    rear=rear+1;
                    front=front +1;
                    q[rear]=item;
                }
                else
                rear=rear+1;
                    q[rear]=item;
            }
        
}
int del()
{
    int k;
    if((front>rear)||(front==-1))
    return(0);
    
    else
    {
        k=q[front];
        front=front+1; 
        return(k);
    }
}

void bfs(int s,int n)
{
    int p;//[1,2,3,4,5]
    add(s);
    vis[s]=1;
    p=del();
    if(p!=0)
        cout<<p<<" "<<endl; //source vertix printed
    while(p!=0) //p=0 is queue empty
    {
        for(int i=1;i<=n;i++)
            {if((a[p][i]==1)&&(vis[i]==0))//adjacent && unvisited
            {
                add(i);
                vis[i]=1; 
            }}
            
        p=del();//delete first adjacent
        
        if(p!=0)//print first adj
            cout<<p<<" "<<endl;
    }
    
    for(int i=1;i<=n;i++)//excluded vertex
    {
        if(vis[i]==0)
        {bfs(i,n);}
        
    }
}

int main()
{
    int n;
    cout<<"Enter number of vertices:"<<endl;
    cin>>n;
    int a[n+1][n+1];
    int s;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<"Enter 1 if "<<i<<" has an edge with "<<j<<":"<<endl;
            cin>>a[i][j];
        }
    }
    
    cout<<"THE ADJACENCY MATRIX IS\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j];
        }
    cout<<"\n";
    }
    cout<<"Enter the source vertex:"<<endl;
    cin>>s;
    cout<<"The bfs is: ";
    bfs(s,n);
    return 0;
}