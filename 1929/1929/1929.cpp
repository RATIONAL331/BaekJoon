#include<iostream>
#include<cmath>
bool isPrime(int n) {
	if (n == 1) { return false; }
	for (int i = 2; i <= std::sqrt(n); i++) { if (n % i == 0) return false; }
	return true;
}

int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = M; i <= N; i++) {
		if (isPrime(i)) printf("%d\n", i);
	}
	
	return 0;
}