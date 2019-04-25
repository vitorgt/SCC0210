#include <bits/stdc++.h> 

using namespace std;

int counter = 0;
void back_tracking(int n, int i, vector<int>avaible){
	if(i <= (int)avaible.size()){	
		if(n == 0){
			counter++;
		}else if(n > 0){
			back_tracking(n - avaible[i], i+1, avaible);
			back_tracking(n, i+1, avaible);
		}
	}
}

int main(int argc, char *argv[]){
	vector<int>avaible;
	vector<int>used;
	int n, x;
	scanf("%d", &n);
	scanf("%d", &x);

	int i = 1;
	while(i*i <= n){
		avaible.push_back(pow(i, x));
		i++;
	}

	back_tracking(n, 0, avaible);

	printf("%d\n", counter);

	return EXIT_SUCCESS;
}