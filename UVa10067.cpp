#include<iostream>
#include<vector>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

int unite(const vector<int> &in){
	int temp = in[0];
	for(int i = 1; i < 4; i++){
		temp *= 10;
		temp += in[i];
	}
	return temp;
}

int main(){
	ios::sync_with_stdio(false);
	int n = 0, nf = 0;
	cin >> n;
	while(n--){
		vector<int> s(5, 0), t(5, 0);
		for(int i = 0; i < 4; i++)
			cin >> s[i];
		s[4] = unite(s);
		for(int i = 0; i < 4; i++)
			cin >> t[i];
		t[4] = unite(t);
		cin >> nf;
		vector<vector<int>> f(nf, vector<int>(5, 0));
		for(int i = 0; i < nf; i++){
			for(int j = 0; j < 4; j++)
				cin >> f[i][j];
			f[i][4] = unite(f[i]);
		}
	}
	return 0;
}
