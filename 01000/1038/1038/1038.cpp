#include<iostream>
#include<algorithm>
using namespace std;

bool a[10];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < i; j++)
			a[9 - j] = true;
		
		do {
			if (N == 0) {
				for (int k = 0; k < 10; k++) {
					if (a[k] == true) {
						cout << 9 - k;
					}
				}	
				return 0;
			}
			N--;
		} while (next_permutation(begin(a), end(a)));
	}
	cout << -1;
}