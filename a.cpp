#include<iostream>
#include<math.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	cout << ceil(n/2) << endl;
	while(n-3 > 0){
		cout << 2 << " ";
		n -= 2;
	}
	cout << n << endl;
	return 0;
}