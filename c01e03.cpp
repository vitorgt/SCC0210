#include<iostream>
#include<string>
#include<set>
#include<iomanip>

using namespace std;
#define INF 0x3f3f3f3f
#define ll long long

int main(){
	ios::sync_with_stdio(false); cout << fixed << setprecision(3);

	string in;
	cin >> in;
	int n = stoi(in);
	set<int> set;
	for(int i = 0; i < n; i++){
		cin >> in;
		set.insert(stoi(in));
	}
	cout << set.size() << endl;

	return 0;

}
