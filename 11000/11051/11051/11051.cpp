#include<iostream>
long long arr[1001][1001] = { 0, };
int C(int N, int K) {
	if (arr[N][K] != 0) return arr[N][K];
	else {
		if (K == 0) return arr[N][K] = 1;
		if (K == N) return arr[N][K] = 1;
		return arr[N][K] = (C(N - 1, K - 1) + C(N - 1, K)) % 10007;
	}
}
int main() {
	int N, K;
	std::cin >> N >> K;
	std::cout << C(N, K);
	return 0;
}