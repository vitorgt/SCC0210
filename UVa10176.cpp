#include<stdio.h>

using namespace std;
#define inf 0x3f3f3f3f

int main(){
	char a = 0;
	int b = 0;
	while(scanf("%c", &a) == 1){
		if(a == '0')
			b = (b << 1) % 131071;
		else if(a == '1')
			b = ((b << 1) + 1) % 131071;
		else if(a == '#'){
			printf(b%131071 ? "NO\n" : "YES\n");
			b = 0;
		}
	}
	return 0;
}
