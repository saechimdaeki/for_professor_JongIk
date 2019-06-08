#include<iostream>
#include<vector>

using namespace std;
string text,pattern;
vector<int>* preprocessing(const string& P){		
	int j = 0;
	int k = -1;
	int m = P.length();
	vector<int>* Fail = new vector<int>(m , 0);
	(*Fail)[0] = -1;
	while(j < m){
		if(k == -1 || P[j] == P[k]){
			j++; k++; (*Fail)[j] = k;
		}else k = (*Fail)[k];
	}
	return Fail;
}

int KMP(const string& A, const string& P){
	vector<int>* Fail = preprocessing(P);
	int CompCnt(0),FindCnt(0),i(0),j(0); 
	int n(A.length());
	int m(P.length());
	while(i < n){
		CompCnt++;
		if(j == -1 || A[i] == P[j]){
			i++; j++;
		}else j = (*Fail)[j];
		
		if(j == m){
			FindCnt++;
			cout << CompCnt << endl;
			j = (*Fail)[j];
		}
	}
	return FindCnt;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> text >> pattern;
	if(!KMP(text, pattern)) cout << "fail";

	return 0;
}

