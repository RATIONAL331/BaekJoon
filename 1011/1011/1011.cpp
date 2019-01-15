#include<iostream>
int calculate(int x, int y, int n) {
	// ���� ���̰� �̵��� �Ÿ����� �۰ų� ���� ��쿡�� �̵��� �ִ� Ƚ���� 1ȸ�Դϴ�.
	if (y - x <= n) return 1;
	// ���� ���̰� �̵��� �Ÿ����ٴ� ũ���� �װ��� �ι� �Ÿ����� ������ �ִ� Ƚ���� 2ȸ�Դϴ�.
	if (y - x <= 2 * n) return 2;
	// ���� ���̰� �̵��� �Ÿ��� �ι躸�� �� ũ�� �ȴٸ� ���� Ƚ�� 2ȸ�� ���ϰ� ���� �Ÿ��� n+1��ŭ �ٽ� �����մϴ�.
	return 2 + calculate(x + n, y - n, n + 1);
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