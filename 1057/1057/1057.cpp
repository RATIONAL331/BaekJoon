#include<iostream>
int main() {
	int N, K, I;
	std::cin >> N >> K >> I;
	if (N == 1) { std::cout << -1; return 0; }
	int cnt = 0;
	while (!(K == I)) {
		K = K / 2 + K % 2;
		I = I / 2 + I % 2;
		cnt++;
	}
	std::cout << cnt;
	return 0;
}