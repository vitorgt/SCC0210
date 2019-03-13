#include<iostream>
#include<vector>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

#define MAX 31 //max sum 16+15

vector<bool> primes(MAX, 1);

void primer(){
	primes[0] = 0;
	int i = 2, j = 0;
	while(i*i < MAX){
		j = i*i;
		while(j < MAX){
			primes[j] = 0;
			j += i;
		}
		i++;
		while(!primes[i] && i < MAX) i++;
	}
}

void primeRing(int i, int n, vector<int> &ring, vector<bool> &used){
	if(i == n){
		for(auto j : ring)
			cout << j << " ";
		cout << endl;
		return;
	}
	for(int j = ((i%2) ? 2 : 3); j <= n; j += 2){
		if(!used[j]){
			if(primes[ring[i-1] + j]){
				if(i+1 == n){
					if(primes[j + 1]){
						used[j] = 1;
						ring.push_back(j);
						primeRing(i+1, n, ring, used);
						ring.pop_back();
						used[j] = 0;
					}
				}
				else{
					used[j] = 1;
					ring.push_back(j);
					primeRing(i+1, n, ring, used);
					ring.pop_back();
					used[j] = 0;
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	primer();
	int cases = 1, in = 0;
	bool init = 0;
	while(cin >> in){
		if(init) cout << endl;
		init = 1;
		cout << "Case " << cases++ << ":" << endl;
		vector<int> ring;
		vector<bool> used(in, 0);
		ring.push_back(1);
		primeRing(1, in, ring, used);
	}
	return 0;
}
