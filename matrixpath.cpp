#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int c[100][100];
int matrix[100][100];
int matrixpath(int n)
{
	c[1][1]=matrix[1][1];
	for(int i=2; i<=n; i++)
	c[i][1]=matrix[i][1]+c[i-1][1];
	for(int j=2; j<=n; j++)
	c[1][j]=matrix[1][j]+c[1][j-1];
	
	for(int i=2; i<=n; i++)
		for(int j=2; j<=n; j++)
			c[i][j]=matrix[i][j]+min(c[i-1][j],c[i][j-1]);
			
	return c[n][n];		
}


int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>matrix[i][j];
			
	cout<<matrixpath(n);
	
}
