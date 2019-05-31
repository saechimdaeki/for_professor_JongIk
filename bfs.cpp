#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<functional>

using namespace std;

void bfs(int start, vector<int> graph[], bool check[]){
   queue<int> q;

   q.push(start);
   check[start] = true;

   while(!q.empty()){
      int tmp = q.front();
      q.pop();
      printf("%d ",tmp+1);
      for(int i=0; i<graph[tmp].size(); i++){
         if(check[graph[tmp][i]] == false){
            q.push(graph[tmp][i]);
            check[graph[tmp][i]] = true;
         }
      }
   }

}

int main (){

   int n, length;
   cin >> n >> length;
   vector<int> graph[n+1];
   bool check [n+1];
   fill(check, check+n+1, false);
   int a,b;
   for(int i=0; i<length; i++){
      cin >> a >> b;
      graph[a-1].push_back(b-1);
      graph[b-1].push_back(a-1);
   }
   
   int start;
   cin >> start;
   
   for(int i=0; i<n; i++) 
   sort(graph[i].begin(), graph[i].end());

   bfs(start-1, graph, check);

   return 0;
}
