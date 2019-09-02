#include<iostream>
int main() {
	int X;
	std::cin >> X;
	if (X == 64) { std::cout << 1; return 0; }
	int ret = 0;
	int length = 0;
	int bar = 64;
	while (X != length) {
		bar /= 2;
		if (bar + length <= X) {
			length += bar;
			ret++;
		}
	}
	std::cout << ret;
	return 0;
}