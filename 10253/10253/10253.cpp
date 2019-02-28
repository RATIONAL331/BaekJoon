#include<iostream>
int gcd(int a, int b) {
	if (b > a) return gcd(b, a);
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
int cal(int a, int b) {
	if (a == 1) return b;

	int c;
	if (b % a == 0) c = b / a;
	else c = b / a + 1;
	
	int tempA = a * c - b;
	int tempB = b * c;

	int GCD = gcd(tempA, tempB);
	tempA = tempA / GCD;
	tempB = tempB / GCD;

	return cal(tempA, tempB);
}
int main() {
	int T;
	std::cin >> T;

	int a, b;
	for (int i = 0; i < T; i++) {
		std::cin >> a >> b;
		std::cout << cal(a, b) << std::endl;
	}
}