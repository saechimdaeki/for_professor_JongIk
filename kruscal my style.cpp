#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[10001];
struct edge {
    int u,v,w; 
    edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int find(int u) {
    if(u == parent[u])
     {
     	return u;
		}   
    return parent[u] = find(parent[u]);
}
 
void merge(int u, int v) { 
    u = find(u);
    v = find(v);    
    parent[v] = u;
}
int compare_comp(const edge& a, const edge& b) {
    return a.w < b.w;
}
int main(void) {
    ios::sync_with_stdio(false); 
	cin.tie(NULL);
    vector<edge> v;
    int V,E;
    long long ans = 0;
    cin >> V >> E;
    int A,B,C;
 
    for(int i = 1; i <= V; i++)
        parent[i] = i;
     
    for(int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        v.push_back(edge(A, B, C));
    }
    sort(v.begin(), v.end(), compare_comp);
    for(auto n : v) {
        if(find(n.v) != find(n.u)) {
        	cout<<n.w<<" ";
			merge(n.u, n.v);
            ans += n.w;
        }   
    }
    cout<<ans;
    return 0;
}
