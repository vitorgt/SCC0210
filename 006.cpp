#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

struct node{
	int id, size;
	vector<node *> content;

	bool hasGift(){
		return content.empty();
	}

	bool operator<(const node &v) const{
		return size > v.size;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int n = 0, m = 0, k = 0, buffer = 0, sum = 0;
	cin >> n >> m >> k;
	vector<node> adr;
	priority_queue<node *> open;
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
				adr[i].content.push_back(&adr[buffer-1]);
			}
		}
	}
	for(int i = 0; i < m; i++){
		cin >> buffer;
		open.push(&adr[buffer-1]);
	}
	while(!open.empty() && k--){
		node *pack = open.top();
		open.pop();
		if(pack->hasGift()){
			sum++;
		}
		else{
			for(auto i : pack->content){
				open.push(i);
			}
		}
	}
	cout << sum << endl;
	return 0;
}
