#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<queue>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define MAX 4

typedef int my;

set<vector<vector<my>>> visited;

struct state{
	vector<vector<my>> board;
	int depth, f;
	bool operator<(const state &a) const{
		return f > a.f;
	}
	bool operator==(const state &a) const{
		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < MAX; j++)
				if(board[i][j] != a.board[i][j])
					return 0;
		return 1;
	}
	state() :
		board(vector<vector<my>>(MAX, vector<my>(MAX, 0))), depth(0), f(0) {}
	state(const state &a) :
		board(vector<vector<my>>(a.board)), depth(a.depth+1), f(0) {}
};

//ostream
#include<algorithm>
#include<iterator>
template<typename T>
ostream &operator<<(ostream &out, const vector<vector<T>> &v){
	if(!v.empty()){
		int i = 0;
		out << '[';
		for(; i < MAX-1; i++)
			out << v[i] << ",\n";
		out << v[i] << "]";
	}
	return out;
}
template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v){
	if(!v.empty()){
		int i = 0;
		out << '[';
		for(; i < MAX-1; i++){
			out << v[i] << ", ";
		}
		//copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
		//out << "\b\b]";
		out << v[i] << "]";
	}
	return out;
}

void next_states(const state &current, vector<state> &next){
	int i = 0, j = 0;
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			if(current.board[i][j] == 0) break;
		}
		if(current.board[i][j] == 0) break;
	}
	cout << current.board << "yo|i" << i << "j" << j << "fuck:" << current.board[i][j] << endl;
	if(i > 0){
		swap(next[0].board[i][j], next[0].board[i-1][j]);//u
		cout << next[0].board << "i-1:" << i-1 << "j:" << j << endl;
	}
	if(j > 0){
		swap(next[1].board[i][j], next[1].board[i][j-1]);//l
		cout << next[1].board << "i:" << i << "j-1:" << j-1 << endl;
	}
	if(j < MAX-1){
		swap(next[2].board[i][j], next[2].board[i][j+1]);//r
		cout << next[2].board << "i:" << i << "j+1:" << j+1 << endl;
	}
	if(i < MAX-1){
		swap(next[3].board[i][j], next[3].board[i+1][j]);//d
		cout << next[3].board << "i+1:" << i+1 << "j:" << j << endl;
	}
}

int heuristic(const state &current, const state &target){
	int d = 0, h = 0;
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			d = abs(current.board[i][j] - target.board[i][j]);
			h += min(d, (MAX*MAX)-d);
		}
	}
	return h + current.depth;
}

string a_star(state &current, const state &target){
	if(visited.find(current.board) == visited.end()){//not found
		visited.insert(current.board);
		priority_queue<state> q;
		q.push(current);
		while(!q.empty()){
			current = q.top();
			q.pop();
			if(current == target)
				return "ans";//out;
			vector<state> next(4, state(current));
			next_states(current, next);
			for(int i = 0; i < 4; i++){
				if(visited.find(next[i].board) == visited.end()){
					visited.insert(next[i].board);
					next[i].f = heuristic(next[i], target);
					q.push(next[i]);
				}
			}
		}
	}
	return "This puzzle is not solvable.";
}

int main(){
	ios::sync_with_stdio(false);
	int n = 0;
	string buffer = "";
	cin >> n;
	while(n--){
		state start, target;
		for(int i = 0; i < MAX; i++){
			for(int j = 0; j < MAX; j++){
				start.board[i][j] = i*MAX + j;
				cin >> buffer;
				try{
					target.board[i][j] = stoi(buffer);
				}catch(const exception &){}
			}
		}
		visited.insert(target.board);
		cout << start.board << endl;
		cout << target.board << endl;
		cout << a_star(start, target) << endl;
		visited.clear();
	}
	return 0;
}
