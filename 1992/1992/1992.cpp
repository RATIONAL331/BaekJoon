#include<iostream>
#include<string>
#include<vector>
bool allSame(bool** board, int height, int curPosY, int curPosX, std::vector<char>& ret) {
	bool init = board[curPosY][curPosX];
	for (int i = curPosY; i < height + curPosY; i++) {
		for (int j = curPosX; j < height + curPosX; j++) {
			if (init != board[i][j]) return false;
		}
	}
	return true;
}
void calculate(bool** board, int height, int curPosY, int curPosX, std::vector<char>& ret) {
	if (height < 1) return;
	// 모두 0이면 0넣고, 1이면 1넣는다.
	if (allSame(board, height, curPosY, curPosX, ret)) board[curPosY][curPosX] ? ret.push_back('1') : ret.push_back('0');
	// 그게 아니라면 4등분해서 조각 조각을 다시 검사해서 0 또는 1 넣는다.
	else {
		ret.push_back('(');
		calculate(board, height / 2, curPosY, curPosX, ret);
		calculate(board, height / 2, curPosY, curPosX + height / 2, ret);
		calculate(board, height / 2, curPosY + height / 2, curPosX, ret);
		calculate(board, height / 2, curPosY + height / 2, curPosX + height / 2, ret);
		ret.push_back(')');
	}
}
int main() {
	int N;
	std::cin >> N;
	// 배열 생성
	bool ** board = new bool*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new bool[N];
	}
	// 영상 넣기
	std::string sigString;
	for (int i = 0; i < N; i++) {
		std::cin >> sigString;
		for (int j = 0; j < N; j++) {
			board[i][j] = sigString.at(j) - '0';
		}
	}
	// 결과값 저장하기
	std::vector<char> ret;
	calculate(board, N, 0, 0, ret);
	// 결과값 출력하기
	for (char c : ret) {
		std::cout << c;
	}
	// 배열 제거
	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}