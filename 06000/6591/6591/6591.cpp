#include<iostream>
long long min(long long i1, long long i2) {
	if (i1 < i2) return i1;
	else return i2;
}
long long combination(long long n, long long k) {
	long long minK = min(k, n - k);
	long long ret = 1;
	for (long long multiple = 1; multiple <= minK; multiple++) {
		ret *= n;
		ret /= multiple;
		n--;
	}
	return ret;
}
int main() {
	long long n, k;
	while (true) {
		std::cin >> n >> k;
		if (n == 0 && k == 0) return 0;
		std::cout << combination(n, k) << std::endl;
	}
	return 0;
}