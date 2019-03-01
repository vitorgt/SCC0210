#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
#define INF 0x3f3f3f3f
#define ll long long

int main(){
	ios::sync_with_stdio(false); cout << fixed << setprecision(3);
	int n = 0, a = 0;
	string in = "";
	cin >> n;
	vector<int> ori;
	for(int i = 0; i < n; i++){
		cin >> a;
		ori.push_back(a-1);
	}
	cin >> in;
	int init = 0;
	for(int i = 0; i < n-1; i++){
		if((in[i] == '1' && in[i+1] == '0') || (in[i] == '1' && i+1 == n-1)){
			//end of sortable vector
			vector<int> isit(&ori[init], &ori[i+2]);
			sort(isit.begin(), isit.end());
			for(int j = 0, k = init; j < isit.size(); j++, k++){
				if(isit[j] != k){
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		else if(in[i] == '0' && in[i+1] == '1'){
			//begin of sortable vector
			init = i+1;
		}
	}
	cout << "YES" << endl;
	return 0;
}
