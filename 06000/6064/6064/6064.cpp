#include<iostream>

//최대공약수를 찾는 함수
int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (a%b == 0) return b;
	return gcd(b, a%b);
}
//최소공배수를 찾는 함수
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

		//  tempX와 tempY는 입력된 x와 y와 각각 비교하기 위한 변수
		int tempX = 1, tempY = 1;

		// i변수는 횟수를 구하는 변수
		int i = 1;
		// 최대 반복횟수는 M과 N의 최소공배수 만큼의 수이다.
		while (i <= lcmMN) {
			if (x == tempX && y == tempY) {
				break;
			}
			tempX++; tempY++;
			if (tempX > M) tempX = 1; // tempX = (tempX - 1) % M + 1;
			if (tempY > N) tempY = 1; // tempY = (tempY - 1) % N + 1;

			i++;
		}
		// i가 M과 N의 최소공배수보다 클 경우 구하지 못한 경우 이므로 -1을 출력
		if (i > lcmMN) std::cout << -1 << std::endl;
		else std::cout << i << std::endl;
	}
	return 0;
}

*/

int calculate(int M, int N, int x, int y) {
	int lcmMN = lcm(M, N);

	int tempX, tempY;
	// x를 고정시키고 y를 늘려가는 방식으로 (M횟수만큼 더함)
	// i변수는 반복횟수를 나타내는 변수임(최소공배수가 최대횟수)
	for (int i = x; i < lcmMN; i += M) {
		// 사실 tempX의 값은 변하지 않는다.(밑의 문장은 사실 필요 없음)
		tempX = (i - 1) % M + 1;
		// tempY의 값이 주기적으로 변한다.
		tempY = (i - 1) % N + 1;
		// 입력된 x, y와 일치한다면 그 즉시 i를 리턴함(이때 tempY == y 만 비교하면 됨)
		if (tempX == x && tempY == y) return i;
	}
	// 위 반복문에서 i를 리턴하지 않았다면 실패한 것으로 -1을 리턴함
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