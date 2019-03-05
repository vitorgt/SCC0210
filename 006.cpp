#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

struct node{
	int id, size;
	priority_queue<node *> content;

	bool hasGift(){
		return content.empty();
	}

	bool operator<(const node &v) const{
		return size > v.size;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int n = 0, m = 0, k = 0, buffer = 0;
	cin >> n >> m >> k;
	vector<node> adr;
	priority_queue<node *> root;
	for(int i = 0; i < n; i++){
		cin >> buffer;
		node in;
		in.id = i;
		in.size = buffer;
		adr.push_back(in);
	}
	for(int i = 0; i < n; i++){
		cin >> buffer;
		if(buffer != 0){
			for(int j = buffer; j > 0; j--){
				cin >> buffer;
				adr[i].content.push(&adr[buffer-1]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << adr[i].id << ":" << adr[i].size;
		if(!adr[i].hasGift()){
			cout << "(";
			for(auto j : adr[i].content){
				cout << j->id << ":" << j->size << " ";
			}
			cout << ")";
		}
		cout << endl;
	}
	for(int i = 0; i < m; i++){
		cin >> buffer;
		root.push(&adr[buffer-1]);
	}
	return 0;
}
