#include<iostream>
#include<string>
#include<cmath>
// 고장난 버튼을 누르면 true리턴 아니면 false 리턴
int main() {
	std::ios::sync_with_stdio(false);
	// 원하는 채널 값 N
	std::string N;
	std::cin >> N;
	// N의 값을 숫자로 변환한 값 integerN
	int integerN = std::stoi(N);
	// 고장난 버튼갯수 M
	int M;
	std::cin >> M;
	// 고장난 버튼 배열 대입하기
	int button;
	int * breakButton = new int[10];
	for (int i = 0; i < 10; i++) {
		breakButton[i] = false;
	}
	for (int i = 0; i < M; i++) {
		std::cin >> button;
		breakButton[button] = true;
	}

	int Case1 = std::abs(integerN - 100);

	for (int i = 0; i <= 999999; i++) {
		// 모두 고장 났는지 확인하기 위한 변수
		bool flag = true;
		std::string current = std::to_string(i);
		for (int j = 0; j < current.length(); j++) {
			int curValue = current.at(j) - '0';
			// 고장 났으면 멈추기
			if (breakButton[curValue]) {
				flag = false;
				break;
			}
		}
		// 모두 고장 안났으면
		if (flag) {
			int compare = std::abs(i - integerN) + current.length();
			if (Case1 > compare){
				Case1 = compare;
			}
		}
	}
	std::cout << Case1;
	delete[] breakButton;
	return 0;
}