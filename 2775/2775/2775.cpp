#include<iostream>

int calculate(int, int);

int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int k, n;
		std::cin >> k >> n;
		std::cout << calculate(k, n) << std::endl;
	}
	return 0;
}

int calculate(int k, int n) {
	int temp = 0;
	if (k == 0) return n;
	for (int i = n; i >= 1; i--) {
		temp += calculate(k - 1, i);
	}
	return temp;
}
