#include<iostream>

using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

void eq(int a, int b, int c){
	for(int x = -100; x <= 100; x++)
		for(int y = -100; y <= 100; y++)
			for(int z = -100; z <= 100; z++)
				if(x+y+z == a && x*y*z == b && x*x+y*y+z*z == c){
					if(x != y && y != z && x != z){
						cout << x << " " << y << " " << z << endl;
						return;
					}
				}
	cout << "No solution.\n";
}

int main(){
	ios::sync_with_stdio(false);
	int in = 0, a = 0, b = 0, c = 0;
	cin >> in;
	while(in--){
		cin >> a >> b >> c;
		eq(a, b, c);
	}
	return 0;
}
