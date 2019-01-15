 #include<iostream>
int calculate(int x, int y, int dim) {
	// 리턴값을 저장하는 temp변수입니다.
	int temp = 0;

	// 남은 길이가 이동할 거리보다 작거나 같을 경우에는 이동할 최대 횟수는 1회입니다.
	if (y - x <= dim) {
		return 1;
	}
	// 남은 길이가 이동할 거리보다는 크지만 그것의 두배 거리보다 작으면 최대 횟수는 2회입니다.
	else if (y - x <= 2 * dim && y - x > dim) {
		return 2;
	}
	// 남은 길이가 이동할 거리의 두배보다 더 크게 된다면 남은 거리를 dim+1만큼 다시 수행합니다.
	else {
		return temp += 2 + calculate(x + dim, y - dim, dim + 1);
	}
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