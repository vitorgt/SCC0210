#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;
#define INF 0x3f3f3f3f
#define ll long long

int main(){

	ios::sync_with_stdio(false); cout << fixed << setprecision(3);

	string in;
	cin >> in;
	vector<char> check;
	check.push_back(in[0]);
	for(int i = 1; i < (int)in.length(); i++){
		if(check.back() == '('){
			if(in[i] == '('){
				check.push_back('(');
			}
			else {
				check.pop_back();
			}
		}
		else{
			check.push_back(in[i]);
		}
	}
	if(check.empty()){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}

	return 0;

}
