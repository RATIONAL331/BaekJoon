#include<iostream>
int main() {
	int sugar;
	std::cin >> sugar;

	int count = 0;

	int x_5 = sugar / 5;
	sugar %= 5;
	count += x_5;

	while (x_5 >= 0 && sugar != 0) {
		if (sugar % 3 == 0) {
			count += sugar / 3;
			sugar %= 3;
		}
		else {
			sugar += 5;
			x_5 -= 1;
			count--;
		}
	}
	if (sugar == 0) {
		std::cout << count;
	}
	else {
		std::cout << -1;
	}

	return 0;
}