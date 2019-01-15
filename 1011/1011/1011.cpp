 #include<iostream>
int calculate(int x, int y, int dim) {
	// ���ϰ��� �����ϴ� temp�����Դϴ�.
	int temp = 0;

	// ���� ���̰� �̵��� �Ÿ����� �۰ų� ���� ��쿡�� �̵��� �ִ� Ƚ���� 1ȸ�Դϴ�.
	if (y - x <= dim) {
		return 1;
	}
	// ���� ���̰� �̵��� �Ÿ����ٴ� ũ���� �װ��� �ι� �Ÿ����� ������ �ִ� Ƚ���� 2ȸ�Դϴ�.
	else if (y - x <= 2 * dim && y - x > dim) {
		return 2;
	}
	// ���� ���̰� �̵��� �Ÿ��� �ι躸�� �� ũ�� �ȴٸ� ���� �Ÿ��� dim+1��ŭ �ٽ� �����մϴ�.
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