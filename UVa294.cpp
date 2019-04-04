#include<iostream>

using namespace std;
#define inf 0x3f3f3f3f

int l = 0, u = 0;
int m = 0, d = 0;

void maxD(){
}

int main(){
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	while(n--){
		cin >> l >> u;
		maxD();
		cout << "Between " << l << " and " << u;
		cout << ", " << m << " has a maximum of ";
		cout << d << " divisors." << endl;
	}
	return 0;
}
