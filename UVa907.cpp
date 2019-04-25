#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
#define inf 0x3f3f3f3f

int c = 0, n = 0;
vector<int> kms, pos;

bool check(int x){
	int y = x, camp = 0;
	for(int i = 0; i < c+1; i++){
		int dif = pos[i+1] + pos[i];
		if(y >= dif){
			y -= dif;
		}
		else{
			camp++;
			y = x-dif;
		}
		if(camp > n || y < 0) return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	int km = 0;//campsites, nights
	while(cin >> c >> n){
		kms.clear();
		pos.clear();
		kms.push_back(0);
		pos.push_back(0);
		for(int i = 1; i < c+2; i++){
			cin >> km;
			kms.push_back(km);
			pos.push_back(kms[i] + pos[i-1]);
		}
		int l = pos[0], r = pos[c+1], dist = inf;
		while(l <= r){
			int m = l + (r - l)/2;
			if(check(m)){
				dist = min(dist, m);
				r = m - 1;
			}
			else
				l = m + 1;
		}
		cout << dist << endl;
	}
	return 0;
}
