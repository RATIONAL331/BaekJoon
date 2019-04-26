#include<iostream>

bool isDecreasing(long long n) {
	bool isDecrease = true;

	int beforeNumber;
	while (n / 10 != 0) {
		beforeNumber = n % 10;
		n = n / 10;
		if (beforeNumber >= n % 10) {
			isDecrease = false;
			break;
		}
	}
	return isDecrease;
}
int main() {
	int N;
	std::cin >> N;

	int count = 0;

	for (long long i = 0; i <= 98765843210; i++) {
		if (isDecreasing(i)) {
			count++;
		}
	}

	std::cout << count;

	return 0;
}