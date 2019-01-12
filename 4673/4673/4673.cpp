#include<iostream>
int d(int n) {
	return n + (n % 10) + ((n / 10) % 10) + ((n / 100) % 10) + ((n / 1000) % 10);
}
int main() {
	bool isTrue[10000] = {};
	for (int i = 0; i < 10000; i++) {
		isTrue[i] = true;
	}
	int dNum;
	for (int i = 1; i < 10000; i++) {
		if (isTrue[i]) {
			dNum = d(i);
			while (dNum < 10000) {
				isTrue[dNum] = false;
				dNum = d(dNum);
			}
		}
	}
	for (int i = 1; i < 10000; i++) {
		if (isTrue[i]) {
			std::cout << i << std::endl;
		}
	}

	return 0;
}