#include<iostream>
#include<iomanip>
#include<unordered_map>
#include<queue>

using namespace std;
#define INF 0x3f3f3f3f
#define ll long long

struct argus{
	int id, pe, it;

	bool operator<(const argus &v) const{
		return id > v.id;
	}
};

int main(){
	ios::sync_with_stdio(false); cout << fixed << setprecision(3);

	string in = "";
	unordered_map<int, priority_queue<argus>> time;
	int n = 0, q = 0, p = 0;
	argus a;
	while((cin >> in) && (in.compare("Register") == 0)){
		cin >> q >> p;
		a.id = q;
		a.pe = p;
		a.it = 1;
		time[p].push(a);
	}
	cin >> n;
	for(int i = 0, elap = 0; elap < n; i++){
		while(!time[i].empty() && elap < n){
			a = time[i].top();
			a.it++;
			cout << a.id << endl;
			time[a.pe*a.it].push(a);
			time[i].pop();
			elap++;
		}
	}
	return 0;
}
