#include<iostream>
int han(int n) {
	if (n >= 1000) return 0;
	if (n < 100) return 1;

	int a, b, c;
	a = (n / 100) % 10;
	b = (n / 10) % 10;
	c = n % 10;

	if (a - b == b - c) return 1;
	else return 0;
}

int main() {
	int n;
	std::cin >> n;
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += han(i);
	}

	std::cout << ret;

	return 0;
}