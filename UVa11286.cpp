#include<iostream>
#include<iomanip>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;
#define INF 0x3f3f3f3f
#define ll long long

int main(){
	ios::sync_with_stdio(false); cout << fixed << setprecision(3);

	string in;
	cin >> in;
	while(stoi(in)){
		int n = stoi(in), max = 0;
		string conc;
		unordered_map<string, int> count;
		vector<int> comb;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 5; j++){
				cin >> in;
				comb.push_back(stoi(in));
			}
			sort(comb.begin(), comb.end());
			conc = "";
			for(auto j : comb){
				conc += to_string(j) + ";";
			}
			count[conc]++;
			comb.clear();
		}
		int rep = 0;
		for(auto i : count){
			if(i.second > max){
				max = i.second;
				rep = 1;
			}
			else if(i.second == max){
				rep++;
			}
		}
		cout << (max > 1 ? max*rep : n) << endl;
		cin >> in;
	}
	return 0;
}
