#include<iostream>
long long gcd(long long A, long long B) {
	if (A < B) return gcd(B, A);
	if (A % B == 0) return B;
	return gcd(B, A % B);
}
int main() {
	long long A, B;
	std::cin >> A >> B;
	std::cout << A * B / gcd(A, B) << std::endl;
	return 0;
}