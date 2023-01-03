#include<iostream>
using namespace std;

int top=-1,a[20][20],vis[20],stack[20];

void dfs(int v,int n, int a[20][20]){
    
	cout<<v<<"-->";
	vis[v]=1;
	for(int i=0;i<=n;i++){
	
		if(a[v][i]==1 && vis[i]==0){
			dfs(i,n,a);
		}
	}
}
int main()
{
    int n;
    cout<<"Enter number of vertices:"<<endl;
    cin>>n;
    int s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter 1 if "<<i<<" has an edge with "<<j<<":"<<endl;
            cin>>a[i][j];
        }
    }
    cout<<"THE ADJACENCY MATRIX IS\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j];
        }
    cout<<"\n";
    }
    cout<<"Enter the source vertex:"<<endl;
    cin>>s;
    dfs(s,n,a);
    return 0;
}