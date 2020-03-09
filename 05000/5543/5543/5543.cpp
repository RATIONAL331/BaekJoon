#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N;
	int minValA = 2001;
	for (int i = 0; i < 3; i++) {
		cin >> N;
		minValA = min(minValA, N);
	}

	int minValB = 2001;
	for (int i = 0; i < 2; i++) {
		cin >> N;
		minValB = min(minValB, N);
	}

	cout << minValA + minValB - 50;
	return 0;
}