#include<iostream>
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
		cout << "Scenario #" << i << endl;
		int teamID = 0, member = 0;
		list<pair<int, list<int>>> queue;
		list<pair<int, list<int>>>::iterator it;
		unordered_map<int, int> teams;
		string in;
		cin >> in;
		while(in.compare("STOP") != 0){
			if(in[0] > '0' && in[0] <= '9'){
				int n = stoi(in);
				for(int j = 0; j < n; j++){
					cin >> member;
					teams.insert(make_pair(member, teamID));
				}
				teamID++;
			}
			else if(in.compare("ENQUEUE") == 0){
				cin >> member;
				int hisTeam = teams.find(member)->second;
				bool set = 0;
				for(it = queue.begin(); it != queue.end(); ++it){
					if(it->first == hisTeam){
						it->second.push_back(member);
						set = 1;
					}
				}
				if(!set){
					list<int> thisQueue;
					thisQueue.push_back(member);
					queue.push_back(make_pair(hisTeam, thisQueue));
				}
			}
			else if(in.compare("DEQUEUE") == 0){
				it = queue.begin();
				cout << it->second.front() << "\n";
				it->second.pop_front();
				if(queue.front().second.empty()){
					queue.pop_front();
				}
			}
			cin >> in;
		}
	}

	return 0;

}
