#include<iostream>
int main() {
	int a, b;
	std::cin >> a >> b;
	int temp_a, temp_b;

	temp_a = (a % 10) * 100 + ((a / 10) % 10) * 10 + a / 100;
	temp_b = (b % 10) * 100 + ((b / 10) % 10) * 10 + b / 100;

	if (temp_a > temp_b) {
		std::cout<<temp_a;
	}
	else {
		std::cout << temp_b;
	}
	return 0;
}