#include<iostream>
int main() {
	int A, B, V;
	std::cin >> A >> B >> V;

	int distance = 0;
	int count = 0;

	while (V - distance > A) {
		int tmp = (V - distance) / A;
		distance += A * tmp - B * tmp;
		count += tmp;
	}
	
	std::cout << count + 1;
	
	return 0;
}