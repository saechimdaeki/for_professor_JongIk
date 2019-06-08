#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int count123;
int count2123;
string text,pattern;
bool patternMatching(const string& text, const string& pattern, int start){
	for(int i = start; i < start+pattern.length(); i++){
		count123++;
		if(text[i] != pattern[i-start]) return false;	
	}	
	return true;
}
int naiveMatching(const string& text, const string& pattern){
	for(int i =0; i < text.length()-pattern.length()+1; i++)
		count2123 += patternMatching(text, pattern, i);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> text >>pattern;
	naiveMatching(text, pattern);
	cout << count123 << " " << count2123;
}
