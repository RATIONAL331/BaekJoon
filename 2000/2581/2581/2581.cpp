#include<iostream>
#include<cmath>
bool isPrime(int n) {
	if (n == 1) {
		return false;
	}
	for (int i = 2; i <= std::sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	int M, N;
	std::cin >> M >> N;
	int ret = 0;
	int temp = 0;
	bool noPrime = true;
	for (int i = M; i <= N; i++) {
		if (isPrime(i)) {
			ret += i;
			if (noPrime) {
				temp = i;
				noPrime = false;
			}
		}
	}
	if (noPrime) {
		std::cout << -1 << std::endl;
	}
	else {
		std::cout << ret << std::endl << temp << std::endl;
	}
	return 0;
}