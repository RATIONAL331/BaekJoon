#include<iostream>
#include<cmath>
int main() {
	int n;
	std::cin >> n;
	int num;
	bool temp;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		temp = true;
		std::cin >> num;
		if (num == 1) {
			continue;
		}
		for (int i = 2; i <= std::sqrt(num); i++) {
			if (num % i == 0) {
				temp = false; 
				break;
			}
		}
		if (temp) ret++;
	}
	std::cout << ret;
	return 0;
}