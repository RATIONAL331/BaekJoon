#include<iostream>

//�ִ������� ã�� �Լ�
int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (a%b == 0) return b;
	return gcd(b, a%b);
}
//�ּҰ������ ã�� �Լ�
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
/*
int main() {
	int T;
	std::cin >> T;
	int M, N, x, y;
	for (int testCase = 0; testCase < T; testCase++) {
		std::cin >> M >> N >> x >> y;
		
		int lcmMN = lcm(M, N);

		//  tempX�� tempY�� �Էµ� x�� y�� ���� ���ϱ� ���� ����
		int tempX = 1, tempY = 1;

		// i������ Ƚ���� ���ϴ� ����
		int i = 1;
		// �ִ� �ݺ�Ƚ���� M�� N�� �ּҰ���� ��ŭ�� ���̴�.
		while (i <= lcmMN) {
			if (x == tempX && y == tempY) {
				break;
			}
			tempX++; tempY++;
			if (tempX > M) tempX = 1; // tempX = (tempX - 1) % M + 1;
			if (tempY > N) tempY = 1; // tempY = (tempY - 1) % N + 1;

			i++;
		}
		// i�� M�� N�� �ּҰ�������� Ŭ ��� ������ ���� ��� �̹Ƿ� -1�� ���
		if (i > lcmMN) std::cout << -1 << std::endl;
		else std::cout << i << std::endl;
	}
	return 0;
}

*/

int calculate(int M, int N, int x, int y) {
	int lcmMN = lcm(M, N);

	int tempX, tempY;
	// x�� ������Ű�� y�� �÷����� ������� (MȽ����ŭ ����)
	// i������ �ݺ�Ƚ���� ��Ÿ���� ������(�ּҰ������ �ִ�Ƚ��)
	for (int i = x; i < lcmMN; i += M) {
		// ��� tempX�� ���� ������ �ʴ´�.(���� ������ ��� �ʿ� ����)
		tempX = (i - 1) % M + 1;
		// tempY�� ���� �ֱ������� ���Ѵ�.
		tempY = (i - 1) % N + 1;
		// �Էµ� x, y�� ��ġ�Ѵٸ� �� ��� i�� ������(�̶� tempY == y �� ���ϸ� ��)
		if (tempX == x && tempY == y) return i;
	}
	// �� �ݺ������� i�� �������� �ʾҴٸ� ������ ������ -1�� ������
	return -1;
}

int main() {
	int T;
	std::cin >> T;
	int M, N, x, y;
	for (int testCase = 0; testCase < T; testCase++) {
		std::cin >> M >> N >> x >> y;
		std::cout << calculate(M, N, x, y) << std::endl;
		
	}
	return 0;
}