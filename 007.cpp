#include<iostream>
#include<vector>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

#define MAX 102

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

void primeRing(int i, int n, vector<int> ring){
	if(i == n){
		for(auto j : ring)
			cout << j << " ";
		cout << endl;
		return;
	}
	for(int j = (i%2)+1; j <= n; j += 2){
		ring.push_back(j);
		primeRing(i+1, n, ring);
		ring.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(false);
	primer();
	int cases = 1, in = 0;
	while(cin >> in){
		cout << "Case " << cases << ":" << endl;
		vector<int> ring;
		ring.push_back(1);
		primeRing(1, in, ring);
		cout << endl;
	}
	return 0;
}
