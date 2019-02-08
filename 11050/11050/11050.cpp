#include<iostream>
int C(int N, int K) {
	if (K == 0) return 1;
	if (K == N) return 1;
	return C(N - 1, K - 1) + C(N - 1, K);
}
int main() {
	int N, K;
	std::cin >> N >> K;
	std::cout << C(N, K);
	return 0;
}