#include<iostream>
int arr[10000] = { 0, };
int fib(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (arr[n] != 0) {
		return arr[n];
	}
	else {
		return arr[n] = fib(n - 1) + fib(n - 2);
	}
}
int main() {
	int n;
	std::cin >> n;
	std::cout << fib(n);
	return 0;
}