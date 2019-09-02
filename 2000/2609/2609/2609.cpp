#include<iostream>
int gcd(int A, int B) {
	if (A < B) return gcd(B, A);
	if (A % B == 0) return B;
	return gcd(B, A % B);
}
int main() {
	int A, B, GCD;
	std::cin >> A >> B;
	GCD = gcd(A, B);
	std::cout << GCD << std::endl;
	std::cout << A * B / GCD << std::endl;
	return 0;
}