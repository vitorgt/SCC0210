#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>

using namespace std;
#define INF 0x3f3f3f3f
#define ll long long

int main(){
	ios::sync_with_stdio(false); cout << fixed << setprecision(3);

	int n = 0;
	while(cin >> n){
		int op = 0, res = 0;
		bool quB = 1, stB = 1, pquB = 1;
		stack<int> st;
		queue<int> qu;
		priority_queue<int> pq;
		for(int i = 0; i < n; i++){
			cin >> op >> res;
			if(op == 1){
				st.push(res);
				qu.push(res);
				pq.push(res);
			}
			else if(op == 2){
				if(stB && res != st.top()){
					stB = 0;
				}
				if(quB && res != qu.front()){
					quB = 0;
				}
				if(pquB && res != pq.top()){
					pquB = 0;
				}
				st.pop();
				qu.pop();
				pq.pop();
			}
		}
		if(((int)stB + (int)quB + (int)pquB) > 1)
			cout << "not sure\n";
		else if(((int)stB + (int)quB + (int)pquB) == 0)
			cout << "impossible\n";
		else if(stB)
			cout << "stack\n";
		else if(quB)
			cout << "queue\n";
		else if(pquB)
			cout << "priority queue\n";
	}
	return 0;
}
