#include<iostream>
int calculate(int x, int y, int dim) {
	if (y - x < dim) return 1;
	else if (y - x == dim) return 2;
	int ret = 2;
	int restDim;
	if (y - x > 2 * dim) {
		restDim = dim + 1;
	}if (y - x < 2 * dim) {
		restDim = dim - 1;
	}

	ret += calculate(x + dim, y - dim, restDim);
	return ret;

}
int main() {
	int T;
	std::cin >> T;

	int x, y;

	for (int i = 0; i < T; i++) {
		std::cin >> x >> y;
		std::cout << calculate(x, y, 1) << std::endl;
	}
	return 0;
}