#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<unordered_map>
#include<iomanip>

using namespace std;
#define INF 0x3f3f3f3f
#define ll long long

int main(){
	ios::sync_with_stdio(false); cout << fixed << setprecision(3);

	int scenario = 0;
	cin >> scenario;
	for(int i = 0; i < scenario; i++){
		int teamID = 0;
		string in;
		list<pair<int, list<int>>> queue;
		unordered_map<int, int> teams;
		cin >> in;
		while(in.compare("STOP") != 0){
			if(in[0] > '0' && in[0] <= '9'){
				int n = 0, member = 0;
				n = atoi(in);
				for(int j = 0; j < n; j++){
					cin >> member;
					teams.insert(make_pair(teamID, member));
				}
				teamID++;
			}
			else if(in.compare("ENQUEUE") == 0){
			}
			else if(in.compare("DEQUEUE") == 0){
			}
			cin >> in;
		}
	}

	return 0;

}
