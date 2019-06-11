#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
 
int V, E;
vector<int> G[10001];
vector<int> T[10001];
vector<vector<int>> scc;
int cur_time; // finish time üũ�� ���� �ð� ����
int ft2vtx[10001]; // ft2vtx[n] = finish time�� n�� ������ ��ȣ
bool visit[10001]; // �湮 üũ �迭
void dfs(int here)
{
    visit[here] = true;
    for (int there : G[here])
    {
        if(!visit[there])
            dfs(there);
    }
    ft2vtx[++cur_time] = here;
}
 
// ������ dfs
void rdfs(int here, vector<int>& newscc)
{
    newscc.push_back(here);
    visit[here] = true;
    for (int there : T[here])
    {
        if(!visit[there])
            rdfs(there, newscc);
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin >> V >> E;
    for (int i = 0; i < E; ++i)
    {
        int from, to;
        cin >> from >> to;
        G[from].push_back(to);
        T[to].push_back(from);
    }
 
    // dfs
    for (int root = 1; root <= V; ++root) {
        if (!visit[root])
            dfs(root);
    }
 
    // finish time�� ū �������� ������ dfs
    memset(visit, 0, sizeof(visit));
    for (int time = V; time >= 1; --time) {
        int root = ft2vtx[time];
        if (!visit[root]) {
            vector<int> newscc;
            rdfs(root, newscc);
            sort(newscc.begin(), newscc.end());
            scc.push_back(newscc);
        }
    }
 
    // ���
    sort(scc.begin(), scc.end());
    cout << scc.size() << "\n";
    for(vector<int>& here : scc) {
        for(int v : here) {
            cout << v << " ";
        }
        cout << "-1\n";
    }
    return 0;
}

/*
sample input:
7 9
1 4
4 5
5 1
1 6
6 7
2 7
7 3
3 7
7 2

sameple output:

3
1 4 5 -1
2 3 7 -1
6 -1

*/ 





