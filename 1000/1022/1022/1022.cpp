#include<iostream>
#include<algorithm>
int cal(int a, int b) {
	int c = std::max(std::abs(a), std::abs(b));
	int ret = 1 + 8 * (c * (c + 1) / 2);
	if (a == c && b == c) return ret; // (0�� ���) ��� ����̰� �� ���ڸ��� �ִ񰪰� ��ġ�ϴ� ���
	if (a == c && b < c) { // (1�� ���) a�� ����̰� b�� c���� ���� ���, �� ������ ���
		return cal(c, c) - (c - b);
	}
	else if (b == -c && a < c) { // (2�� ���) b�� �����̰� a�� c���� ������� ���� �� ���
		return cal(c, -c) - (c - a);
	}
	else if (a == -c && b > -c) { // (3�� ���) a�� �����̰� b�� -c���� ū ��� ���� �� ���
		return cal(-c, -c) - (b + c);
	}
	else if (b == c && a > -c) { // (4�� ���) b�� ����̰� a�� -c���� ū ��� ������ �� ���
		return cal(-c, c) - (a + c);
	}
}
int main() {
	int r1, c1, r2, c2;
	std::cin >> r1 >> c1 >> r2 >> c2;  
	// ����� ���� �ִ� ���� ���ϴ� ����
	int max = 0;
	for (int a = r1; a <= r2; a++) {
		for (int b = c1; b <= c2; b++) {
			max = std::max(max, cal(a, b));
		}
	}
	int digit = 1; // �ִ� ���� �ڸ����� ���ϴ� ����
	while (max / 10 != 0) {
		max /= 10;
		digit++;
	}
	for (int a = r1; a <= r2; a++) {
		for (int b = c1; b <= c2; b++) {
			// printf("%*d, �ڸ���, ǥ���� ��)
			printf("%*d ", digit, cal(a, b)); // printf %*d�� �ڸ��� ������ ����� �� �ִ�.
		}
		std::cout << std::endl;
	}
	return 0;
}