#include<iostream>
long long fac(int N) {
	if (N == 0) return 1;
	if (N == 1) return 1;
	return N * fac(N - 1);
}
int main() {
	int N, K;
	std::cin >> N;
	std::cout << fac(N);
	return 0;
}