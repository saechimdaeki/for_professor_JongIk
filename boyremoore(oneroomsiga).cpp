#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string text,pattern;
int** computejump(const string& P){
	int m = P.length();
	int i,j = 0;
	int** table = new int*[2];
	table[0] = new int[m];
	table[1] = new int[m];
	for(i= 0; i<m; i++){
		table[0][i] = P[i];
		table[1][i] = (m-1)-i;
	}
	table[1][m-1] = m;
	for(i=0; i<m; i++)
		for(j=i+1; j<m; j++)
			if(P[i] == P[j])
				table[1][i] < table[1][j] ? table[1][j] = table[1][i] : table[1][i] = table[1][j];
	return table;
}
int lookup(int** table, int m, char a){
	for(int i = 0; i<m; i++)
		if(table[0][i] == a) return table[1][i];
	return m;
}
int BoyerMooreHorspool(const string& A, const string& P){
	int n = A.length();
	int m = P.length(); 
	int CompCnt = 0;
	int FindCnt = 0;
	int** Jump = computejump(P);		
	int i = 0;
	int j,k;
	while(i <= n-m+1){
		j = m-1;      //패턴 포인터 
		k = i+m-1;    //i 기준으로 패턴 매칭 포인터
		while( j > -1 && P[j] == A[k]){
			CompCnt++;
			j--;
			k--;
		}
		if( j == -1 ) FindCnt++;
		i += lookup(Jump, m, A[i+m-1]);
	}
	cout << CompCnt << " ";
	return FindCnt;
}
int main(){
	cin >> text >> pattern;
	cout << BoyerMooreHorspool(text, pattern);
	return 0;
}

