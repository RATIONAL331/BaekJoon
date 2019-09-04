#include<iostream>
#include<cmath>
int calculate(int height, int r, int c) {
	if (height == 2) {
		return r * 2 + c * 1;
	}
	if (r < height / 2 && c < height / 2) {
		return calculate(height / 2, r, c);
	}
	else if (r < height / 2 && c >= height / 2) {
		return std::pow(4, std::log2(height) - 1) + calculate(height / 2, r, c - height / 2);
	}
	else if (r >= height / 2 && c < height / 2) {
		return std::pow(4, std::log2(height) - 1) * 2 + calculate(height / 2, r - height / 2, c);
	}
	else {
		return std::pow(4, std::log2(height) - 1) * 3 + calculate(height / 2, r - height / 2, c - height / 2);
	}
	return 0;
}
int main() {
	int N, r, c;
	std::cin >> N >> r >> c;
	int height = std::pow(2, N);
	std::cout << calculate(height, r, c);
	return 0;
}