#include<iostream>
#include<vector>

using namespace std;
#define inf 0x3f3f3f3f

#define MAX 1000006

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

int inverseN(int n){
	int r = 0;
	while(n){
		r *= 10;
		r += n%10;
		n /= 10;
	}
	return r;
}

int main(){
	ios::sync_with_stdio(false);
	primer();
	int in = 0;
	while(cin >> in){
		if(primes[in] && primes[inverseN(in)] && in != inverseN(in)){
			cout << in << " is emirp." << endl;
		}
		else if(primes[in]){
			cout << in << " is prime." << endl;
		}
		else{
			cout << in << " is not prime." << endl;
		}
	}
	return 0;
}
