#include<iostream>
#include<cmath>
bool isPrime(int n) {
	if (n == 1) { return false; }
	for (int i = 2; i <= std::sqrt(n); i++) { 
		if (n % i == 0) { return false; }
	}
	return true;
}
void partition(int n) {
	int left, right, divide;
	left = n / 2; right = n / 2; divide = n / 2 - 1;
	for (int i = 0; i < divide; i++) {
		if (isPrime(left - i) && isPrime(right + i)) {
			std::cout << left - i << " " << right + i << std::endl;
			return;
		}
	}
}
int main() {
	int T;
	std::cin >> T;
	int num;
	for (int i = 0; i < T; i++) {
		std::cin >> num;
		partition(num);
	}
	return 0;
}