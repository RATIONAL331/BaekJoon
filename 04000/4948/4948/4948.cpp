#include<iostream>
#include<cmath>
bool isPrime(int n) {
	if (n == 1) { return false; }
	for (int i = 2; i <= std::sqrt(n); i++) {
		if (n%i == 0) { return false; }
	}
	return true;
}
int main() {
	int N;
	int ret;
	while (true) {
		std::cin >> N;
		if (N == 0) return 0;
		ret = 0;
		for (int i = N + 1; i <= 2 * N; i++) {
			if (isPrime(i)) { ret++; }
		}
		std::cout << ret << std::endl;
	}
	return 0;
}