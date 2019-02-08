#include<iostream>
long long arr[101][101] = { 0, };
long long C(int N, int M) {
	if (arr[N][M] != 0) return arr[N][M];
	//if (M > N / 2) return arr[N][M] = C(N, N - M);
	if (M == 0 || N == M) return arr[N][M] = 1;
	//if (M == 1 || N - M == 1)return arr[N][M] = N;
	return arr[N][M] = C(N - 1, M - 1) + C(N - 1, M);
}
int main() {
	int N, M;
	std::cin >> N >> M;
	std::cout << C(N, M);
	return 0;
}
//BigInteger구현하기