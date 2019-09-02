#include<iostream>
int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	long long sum = a * b*c;
	int digits[10];
	for (int i = 0; i < 10; i++) digits[i] = 0;
	while (sum != 0) {
		digits[sum % 10]++;
		sum /= 10;
	}
	for (int i = 0; i < 10; i++) std::cout << digits[i] << std::endl;
	return 0;
}