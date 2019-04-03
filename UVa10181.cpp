#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
#define inf 0x3f3f3f3f
#define PUZZLE_SIZE 4

typedef int my;

string moves = "";

pair<my, my> find_zero(const vector<vector<my>> &board){
	for(int i = 0; i < PUZZLE_SIZE; i++)
		for(int j = 0; j < PUZZLE_SIZE; j++)
			if(board[i][j] == 0)
				return make_pair(i, j);
	return make_pair(-1, -1);
}

int H(vector<vector<my>> &board){
	int h = 0;
	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			if(board[i][j] == 0) continue;
			int expect_i = (board[i][j] - 1) / 4;
			int expect_j = (board[i][j] - 1) % 4;
			h += abs(expect_i - i) + abs(expect_j - j);
		}
	}
	return h;
}

bool is_solvable(vector<vector<my>> &board){
	int cnt = 0, x = 0;
	vector<bool> occur(PUZZLE_SIZE*PUZZLE_SIZE, 0);
	vector<bool>::iterator it = occur.begin();
	for(int i = 0; i < PUZZLE_SIZE; i++){
		for(int j = 0; j < PUZZLE_SIZE; j++){
			if(board[i][j] == 0){
				x = i;
			}
			else{
				cnt += count(it + 1, it + board[i][j], 0);
				occur[board[i][j]] = 1;
			}
		}
	}
	return (cnt + (x + 1)) % 2 == 0;
}

void moveU(vector<vector<my>> &board, my y0, my x0){ swap(board[y0][x0], board[y0-1][x0]); }
void moveD(vector<vector<my>> &board, my y0, my x0){ swap(board[y0][x0], board[y0+1][x0]); }
void moveL(vector<vector<my>> &board, my y0, my x0){ swap(board[y0][x0], board[y0][x0-1]); }
void moveR(vector<vector<my>> &board, my y0, my x0){ swap(board[y0][x0], board[y0][x0+1]); }

int dfs(vector<vector<my>> &board, int limit, int nmoves, char prev_move){
	pair<my, my> zero = find_zero(board);
	my y0 = zero.first, x0 = zero.second;
	int h = H(board), mov = 0;
	if(h == 0)
		return nmoves;
	if(h + nmoves + 1 >= limit)
		return -1;

	//Up
	if(prev_move != 'D' && x0 != 0){
		moveU(board, y0--, x0);
		moves += 'U';
		mov = dfs(board, limit, nmoves + 1, 'U');
		if(mov >= 0)
			return mov;
		moveD(board, y0++, x0);
		moves.pop_back();
	}
	//Down
	if(prev_move != 'U' && x0 != PUZZLE_SIZE-1){
		moveD(board, y0++, x0);
		moves += 'D';
		mov = dfs(board, limit, nmoves + 1, 'D');
		if(mov >= 0)
			return mov;
		moveU(board, y0--, x0);
		moves.pop_back();
	}
	//Left
	if(prev_move != 'R' && y0 != 0){
		moveL(board, y0, x0--);
		moves += 'L';
		mov = dfs(board, limit, nmoves + 1, 'L');
		if(mov >= 0)
			return mov;
		moveR(board, y0, x0++);
		moves.pop_back();
	}
	//Right
	if(prev_move != 'L' && y0 != PUZZLE_SIZE-1){
		moveR(board, y0, x0++);
		moves += 'R';
		mov = dfs(board, limit, nmoves + 1, 'R');
		if(mov >= 0)
			return mov;
		moveL(board, y0, x0--);
		moves.pop_back();
	}

	//Failed
	return -1;
}

int solve(vector<vector<my>> &board, int limit){
	int movs = 0, max_cost = H(board);
	if(max_cost ==  0)//is solved
		return 0;
	if(!is_solvable(board))
		return -1;
	while(max_cost <= limit){
		vector<vector<my>> board_copy(board);
		movs = dfs(board_copy, max_cost, 0, ' ');
		if(movs < 0){
			if(max_cost == limit)
				break;
			else
				max_cost = min(limit, max_cost + 5);
		}
		else
			return movs;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	int n = 0;
	string buffer = "";
	cin >> n;
	while(n--){
		vector<vector<my>> board(PUZZLE_SIZE, vector<my>(PUZZLE_SIZE, 0));
		moves = "";
		for(int i = 0; i < PUZZLE_SIZE; i++){
			for(int j = 0; j < PUZZLE_SIZE; j++){
				cin >> buffer;
				try{
					board[i][j] = stoi(buffer);
				}catch(const exception &){
					board[i][j] = 0;
				}
			}
		}
		if(solve(board, 50) < 0)
			cout << "This puzzle is not solvable.\n";
		else
			cout << moves << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////

//ostream
#include<algorithm>
#include<iterator>
template<typename T>
ostream &operator<<(ostream &out, const vector<vector<T>> &v){
	if(!v.empty()){
		int i = 0;
		out << '[';
		for(; i < PUZZLE_SIZE-1; i++)
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
		for(; i < PUZZLE_SIZE-1; i++){
			out << v[i] << ", ";
		}
		out << v[i] << "]";
	}
	return out;
}
