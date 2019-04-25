//REFERENCE
//https://www.geeksforgeeks.org/printing-items-01-knapsack/

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int n = 0, t = 0, tmp = 0;

void cd(vector<int> &len){
	vector<vector<int>> cds(len.size()+1, vector<int>(n+1, 0));
	for(int i = 0; i < (int)len.size(); i++){
		for(int w = 0; w <= n; w++){
			if(i == 0 || w == 0){
				cds[i][w] = 0;
			}
			else if(len[i-1] <= w){
				cds[i][w] = max(len[i-1]+cds[i-1][w-len[i-1]], cds[i-1][w]);
			}
			else{
				cds[i][w] = cds[i-1][w];
			}
		}
	}
	int ans = cds[(int)len.size()][n], w = n;
	for(int i = (int)len.size(); i > 0 && ans > 0; i--){
		if(ans != cds[i-1][w]){
			cout << len[i-1] << " ";
			ans -= len[i-1];
			w -= len[i-1];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	vector<int> len;
	while(cin >> n >> t){
		len.clear();
		for(int i = 0; i < t; i++){
			cin >> tmp;
			len.push_back(tmp);
		}
		cd(len);
	}
	return 0;
}
