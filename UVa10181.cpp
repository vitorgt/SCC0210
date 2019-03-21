#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define MAX 3

set<vector<vector<char>>> visited;

//ostream
#include<algorithm>
#include<iterator>
template<typename T>
ostream &operator<<(ostream &out, const vector<vector<T>> &v){
	if(!v.empty()){
		out << '[';
		for(auto i : v){
			out << i << ",\n";
		}
		out << "\b\b]";
	}
	return out;
}
template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v){
	if(!v.empty()){
		out << '[';
		copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
		out << "\b\b]";
	}
	return out;
}

//int dir[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};/*u,l,r,d*/

int main(){
	ios::sync_with_stdio(false);
	int n = 0;
	string buffer = "";
	cin >> n;
	while(n--){
		vector<vector<char>> board(MAX, vector<char>(MAX, 0));
		for(int i = 0; i < MAX; i++){
			for(int j = 0; j < MAX; j++){
				cin >> buffer;
				try{
					board[i][j] = stoi(buffer);
				}catch(const exception &){
					//board[i][j] = 0;
				}
			}
		}
		visited.insert(board);
		cout << board << endl;
	}
	return 0;
}
