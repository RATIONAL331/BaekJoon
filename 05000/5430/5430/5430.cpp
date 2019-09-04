#include<iostream>
#include<string>
#include<deque>
bool functionD(std::deque<int>& deque, bool left) {
	if (deque.empty()) return false; // 비었다면 false리턴
	if (left) deque.pop_front(); // 짝수만큼 뒤집혔다면 맨 앞의 원소 삭제
	else deque.pop_back(); // 홀수만큼 뒤집혔다면 맨 뒤의 원소 삭제
	return true;
}
void printDeque(const std::deque<int>& deque, bool left) {
	if (deque.empty()) { // 비어있는 덱을 출력하면 비어있는 덱을 따로 표시해서 출력한다.
		std::cout << "[]" << std::endl;
		return;
	}
	std::cout << "[";
	if (left) { // 짝수만큼 뒤집으면 배열에 있는 그대로 출력
		for (int i = 0; i < deque.size() - 1; i++) {
			std::cout << deque.at(i) << ",";
		}
		std::cout << deque.at(deque.size() - 1) << "]" << std::endl;
	}
	else { // 홀수만큼 뒤집으면 배열 반대로 출력
		for (int i = deque.size() - 1; i >= 1; i--) {
			std::cout << deque.at(i) << ",";
		}
		std::cout << deque.at(0) << "]" << std::endl;
	}
}
int main() {
	int T;
	std::cin >> T;

	std::string p;
	int n;
	std::string array;
	for (int i = 0; i < T; i++) {
		std::cin >> p; // 명령어 입력
		std::cin >> n; // 원소 갯수 입력
		std::cin >> array; // 배열 상태 입력

		std::deque<int> deque;

		if (n > 0) { // 원소의 수가 적어도 한 개 이상일 때만 생각하자 : 0일 때는 다르게 처리
			std::string num = ""; // temp변수
			for (char c : array) { // 배열 상태의 원소를 하나씩 비교
				if (c == ',' || c == ']') { // , 또는 ]를 만나면 숫자가 끝났으므로 모여진 숫자를 진짜 숫자로 만들고 덱에 넣는다.
					deque.push_back(std::stoi(num));
					num = ""; // 다시 초기화
				}
				else if (c != '[') num += c; // 숫자를 만나면 모으기
			}
		}

		bool success = true; //성공했는지 나타내는 변수
		bool left = true; // 뒤집어져있는지 확인하는 변수
		for (char function : p) { // 명령어 하나씩 비교
			if (function == 'R') { // 뒤집는 명령어이면
				left = !left; // 뒤집는 변수를 뒤집는다.
			}
			else { // function == 'D'
				if (!functionD(deque, left)) success = false; // 삭제할 때, 비어있다면 실패했다고 표기
			}
		}
		if (!success) std::cout << "error" << std::endl;
		else printDeque(deque, left);
	}
	return 0;
}