#include<iostream>
int gcd(int A, int B) {
	if (A < B) return gcd(B, A);
	if (A % B == 0) return B;
	return gcd(B, A % B);
}
int main() {
	int T;
	std::cin >> T;

	int A, B;
	for (int i = 0; i < T; i++) {
		std::cin >> A >> B;
		std::cout << A * B / gcd(A, B) << std::endl;
	}
	return 0;
}