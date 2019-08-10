#include<iostream>
using namespace std;

int main() {
	int max = -987654321;
	int maxIdx = -1;

	int num;
	for (int i = 1; i <= 9; i++) {
		cin >> num;
		if (max < num) {
			max = num;
			maxIdx = i;
		}
	}

	cout << max << '\n';
	cout << maxIdx;

	return 0;
}