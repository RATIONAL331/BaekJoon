#include<iostream>
int main() {
	int n;
	int sum = 0;
	int avg;
	for (int i = 0; i < 5; i++) {
		std::cin >> n;
		if (n < 40) sum += 40;
		else sum += n;
	}
	avg = sum / 5;
	std::cout << avg;
	return 0;
}