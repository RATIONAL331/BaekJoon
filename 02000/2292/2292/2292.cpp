#include<iostream>
int main() {
	int n;
	std::cin >> n;

	int k = 1;

	int i = 1;

	while (k < n) {
		k = k + 6 * i;
		i++;
	}

	std::cout << i;

	return 0;
}