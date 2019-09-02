#include<iostream>
int main() {
	int a, b, c, d, e, f, g, h;
	std::cin >> a >> b >> c >> d >> e >> f >> g >> h;
	if (a == 1) {
		if (b == 2 && c == 3 && d == 4 && e == 5 && f == 6 && g == 7 && h == 8) {
			std::cout << "ascending";
		}
		else {
			std::cout << "mixed";
		}
	}
	else if (a == 8) {
		if (b == 7 && c == 6 && d == 5 && e == 4 && f == 3 && g == 2 && h == 1) {
			std::cout << "descending";
		}
		else {
			std::cout << "mixed";
		}
	}
	else {
		std::cout << "mixed";
	}
	return 0;
}