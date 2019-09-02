#include<iostream>
const int DIVISION = 1000000;
const int period = 15 * DIVISION / 10;
int fib[period] = { 0, 1 };
int main() {
	long long n;
	std::cin >> n;
	for (int i = 2; i < period; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % DIVISION;
	}
	std::cout << fib[n % period];
	return 0;
}