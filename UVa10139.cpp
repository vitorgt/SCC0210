#include<iostream>
#include<vector>

using namespace std;
#define inf 0x3f3f3f3f

#define MAX 50004

vector<bool> primes(MAX, 1);
vector<int> p;

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
	for(i = 2; i < MAX; i++){
		while(!primes[i] && i < MAX) i++;
		if(primes[i]) p.push_back(i);
	}
}

bool divide(int f, int d){
	for(int i = 0; i < (int)p.size() && p[i]*p[i] <= d; i++){
		if(d%p[i] == 0){
			int cnt1 = 0;
			while(d%p[i] == 0){
				cnt1++;
				d /= p[i];
			}
			long long tmp = p[i], cnt2 = 0;
			while(tmp <= f){
				cnt2 += f/tmp;
				tmp *= p[i];
			}
			if(cnt2 < cnt1) return 0;
		}
	}
	if(d != 1 && f < d) return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	primer();
	int f = 0, d = 0;
	while(cin >> f >> d){
		if(divide(f, d))
			cout << d << " divides " << f << "!" << endl;
		else
			cout << d << " does not divide " << f << "!" << endl;
	}
	return 0;
}
