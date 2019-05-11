#include<iostream>
#include<algorithm>

using namespace std;

int grid[3][100];
int dp[100][4]; 

int w(int col, int pattern)
{
   switch(pattern)
   {
      case 0:
         return grid[0][col];
      case 1:
         return grid[1][col];
      case 2:
         return grid[2][col];
      case 3:
         return grid[0][col] + grid[2][col];
   }
}

int main(){
   int m;
   cin >> m;
   
   for(int i=0; i<3; ++i)
      for(int j=0; j<m; ++j)
         cin >> grid[i][j];
   
   for(int p=0; p<4; ++p) dp[0][p] = w(0, p);
   
   for(int i=1; i<m; ++i){
      for(int p=0; p<4; ++p){
         int maxpeb;
         switch(p)
         {
            case 0:
               maxpeb = max(dp[i-1][1], dp[i-1][2]); break;
            case 1:
               maxpeb = max(max(dp[i-1][3],dp[i-1][2]),dp[i-1][0]); break;
            case 2:
               maxpeb = max(dp[i-1][0], dp[i-1][1]); break;
            case 3:
               maxpeb = dp[i-1][1]; break;
         }
         dp[i][p] = maxpeb + w(i, p);
      }
   }
   
   cout << *max_element(dp[m-1], dp[m-1]+4);
} 
