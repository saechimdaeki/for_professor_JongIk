#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool check[]){
	check[start]= true;
	cout<<start+1<<" ";

	for(int i=0; i < graph[start].size(); i++){
		int next = graph[start][i];
		if(check[next]==false) 
		dfs(next, graph, check);
	}
}

int main (){

	int n, length;
	cin >> n >> length;

	vector<int> graph[n+1];
	bool check [n+1];
	fill(check, check+n+1, false);
	
	int a, b;
	for(int i=0; i<length; i++){
		cin >> a >> b;

		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	int start;
	cin >> start;

	for(int i=0; i<n; i++) 
	sort(graph[i].begin(), graph[i].end());
	
	dfs(start-1, graph, check);

	return 0;
}
