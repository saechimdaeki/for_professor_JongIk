#include <iostream>
#include <vector>
#include <queue>
#include<functional>
#include<algorithm>
using namespace std;
int N, M;
int inDegree[32001];
vector<int> graph[32001];
void BFS()
{
        queue<int> q;
        for (int i = 1; i <= N; i++)
                 if (!inDegree[i])
                         q.push(i);
        while (!q.empty())
        {
                 int cur = q.front();
                 q.pop();
                 cout << cur << " ";
                 for (int i = 0; i <graph[cur].size(); i++)
                 {
                         inDegree[graph[cur][i]]--;
                         if (!inDegree[graph[cur][i]])
                                 q.push(graph[cur][i]);
                 }
        }
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> N >> M;
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b; 
            graph[a].push_back(b);
            inDegree[b]++;
        }
        BFS();
}

