//REFERENCES
//http://codealltheproblems.blogspot.com/2015/07/uva-10407-simple-division.html

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define inf 0x3f3f3f3f

int gcd(int a, int b){ return (a == 0) ? b : gcd(b % a, a); }

int main(){
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	while(n){
		vector<int> in;
		while(n){
			in.push_back(n);
			cin >> n;
		}
		unique(in.begin(), in.end());
		vector<int> d;
		for(int i = 1; i < (int)in.size(); i++)
			d.push_back(in[i] - in[i - 1]);
		int g = abs(d[0]);
		for(int i = 1; i < (int)d.size(); i++)
			g = gcd(g, abs(d[i]));
		cout << g << endl;
		cin >> n;
	}
	return 0;
}
