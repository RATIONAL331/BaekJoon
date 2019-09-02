#include<iostream>
#include<algorithm>
int cal(int a, int b) {
	int c = std::max(std::abs(a), std::abs(b));
	int ret = 1 + 8 * (c * (c + 1) / 2);
	if (a == c && b == c) return ret; // (0번 경우) 모두 양수이고 그 숫자마저 최댓값과 일치하는 경우
	if (a == c && b < c) { // (1번 경우) a는 양수이고 b가 c보다 작은 경우, 즉 밑줄의 경우
		return cal(c, c) - (c - b);
	}
	else if (b == -c && a < c) { // (2번 경우) b가 음수이고 a가 c보다 작은경우 왼쪽 줄 경우
		return cal(c, -c) - (c - a);
	}
	else if (a == -c && b > -c) { // (3번 경우) a가 음수이고 b가 -c보다 큰 경우 위쪽 줄 경우
		return cal(-c, -c) - (b + c);
	}
	else if (b == c && a > -c) { // (4번 경우) b가 양수이고 a가 -c보다 큰 경우 오른쪽 줄 경우
		return cal(-c, c) - (a + c);
	}
}
int main() {
	int r1, c1, r2, c2;
	std::cin >> r1 >> c1 >> r2 >> c2;  
	// 출력을 위해 최대 수를 구하는 과정
	int max = 0;
	for (int a = r1; a <= r2; a++) {
		for (int b = c1; b <= c2; b++) {
			max = std::max(max, cal(a, b));
		}
	}
	int digit = 1; // 최대 수의 자릿수를 구하는 변수
	while (max / 10 != 0) {
		max /= 10;
		digit++;
	}
	for (int a = r1; a <= r2; a++) {
		for (int b = c1; b <= c2; b++) {
			// printf("%*d, 자릿수, 표시할 수)
			printf("%*d ", digit, cal(a, b)); // printf %*d는 자릿수 단위를 출력할 수 있다.
		}
		std::cout << std::endl;
	}
	return 0;
}