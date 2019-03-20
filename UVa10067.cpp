#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

struct state{
	vector<char> digit;
	int depth, f;
	bool operator<(const state &a) const{
		return f > a.f;
	}
	bool operator==(const state &a) const{
		for(int i = 0; i < 4; i++)
			if(digit[i] != a.digit[i])
				return 0;
		return 1;
	}
	state() :
		digit(vector<char>(4, 0)), depth(0), f(0) {}
};

void printS(const state &a){
	cout << "digits: ";
	for(auto &e : a.digit)
		cout << e << " ";
	cout << "depth: " << a.depth << " f: " << a.f << endl;
}

char moves [8][4]= {
	{-1, 0, 0, 0},
	{ 1, 0, 0, 0},
	{ 0,-1, 0, 0},
	{ 0, 1, 0, 0},
	{ 0, 0,-1, 0},
	{ 0, 0, 1, 0},
	{ 0, 0, 0,-1},
	{ 0, 0, 0, 1}};

void next_states(const state &current, vector<state> &next){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 4; j++){
			next[i].digit[j] = (current.digit[j] + moves[i][j])%10;
			if(next[i].digit[j] < 0) next[i].digit[j] = 9;
		}
		next[i].depth = current.depth+1;
	}
}

int heuristic_cost(const state &current, const state &target){
	int d = 0, h = 0;
	for(int i = 0; i < 4; i++){
		d = abs(current.digit[i] - target.digit[i]);
		h += min(d, 10-d);
	}
	return h + current.depth;
}

int a_star(state current, state target, vector<vector<vector<vector<bool>>>> &visited){
	printS(current);
	vector<state> next(8, state());
	priority_queue<state> q;
	if(!visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]]){
		visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]] = 1;
		q.push(current);
		while(!q.empty()){
			current = q.top();
			q.pop();
			if(current == target)
				return current.depth;
			next_states(current, next);
			for(int i = 0; i < 8; i++){
				if(!visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]]){
					visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]] = 1;
					next[i].f = heuristic_cost(next[i], target);
					q.push(next[i]);
				}
			}
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	int n = 0, nf = 0;
	cin >> n;
	while(n--){
		state start, target, aux;
		for(int i = 0; i < 4; i++){
			cin >> start.digit[i];
			start.digit[i] -= '0';
		}
		for(int i = 0; i < 4; i++){
			cin >> target.digit[i];
			target.digit[i] -= '0';
		}
		cin >> nf;
		vector<vector<vector<vector<bool>>>> visited(10, vector<vector<vector<bool>>>(10, vector<vector<bool>>(10, vector<bool>(10, 0))));
		for(int i = 0; i < nf; i++){
			for(int j = 0; j < 4; j++){
				cin >> aux.digit[i];
				aux.digit[i] -= '0';
			}
			visited[aux.digit[0]][aux.digit[1]][aux.digit[2]][aux.digit[3]] = 1;
		}
		start.depth = 0;
		cout << a_star(start, target, visited) << endl;
	}
	return 0;
}
