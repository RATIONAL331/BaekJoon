#include<iostream>
int gcd(int A, int B) {
	if(B > A) return gcd(B, A);
	if (A % B == 0)return B;
	return gcd(B, A % B);

}
int main() {
	int N;
	std::cin >> N;
	
	int first_radius;
	std::cin >> first_radius;	
	
	int rest_radius;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> rest_radius;
		int GCD = gcd(first_radius, rest_radius);
		std::cout << first_radius / GCD << "/" << rest_radius / GCD << std::endl;
	}
	return 0;
}