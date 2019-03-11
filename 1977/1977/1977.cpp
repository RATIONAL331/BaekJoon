#include<iostream>
#include<cmath>
int main() {
	int arr[101];
	for (int i = 1; i <= 100; i++) {
		arr[i] = i * i;
	}
	int M, N;
	std::cin >> M >> N;

	double dM, dN;
	dM = std::sqrt(M);
	dN = std::sqrt(N);

	M = std::ceil(dM);
	N = std::floor(dN);

	int ret = 0;

	for (int i = M; i <= N; i++) {
		ret += arr[i];
	}
	if (ret != 0)
		std::cout << ret << std::endl << arr[M];
	else
		std::cout << -1;
	
	return 0;
}