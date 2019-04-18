#include<iostream>
#include<vector>
bool checkBoard(std::pair<int, int>** board, int height, int weight, int row, int col) {
	if (row < 0 || col < 0 || row >= height || col >= height) return false;
	if (board[row][col].first < 0) return false;
	return true;
}
void diffusionInit(std::pair<int, int>** board, int height, int weight, int row, int col) {
	if (board[row][col].first < 5) return;
	// 주변의 갯수
	int count = 0;
	// 미세먼지를 5로 나눈 갯수
	int tmp = board[row][col].first / 5;
	
	// 주변으로 갈 수 있는 갯수를 먼저 구합니다.
	// 주변으로 갈 수 있다면 5로나눈 만큼 더합니다.
	// 오른쪽
	if (checkBoard(board, height, weight, row, col + 1)) {
		board[row][col + 1].second += tmp;
		count++;
	}
	// 아래쪽
	if (checkBoard(board, height, weight, row + 1, col)) {
		board[row + 1][col].second += tmp;
		count++;
	}
	// 왼쪽
	if (checkBoard(board, height, weight, row, col - 1)) {
		board[row][col - 1].second += tmp;
		count++;
	}
	// 위쪽
	if (checkBoard(board, height, weight, row - 1, col)) {
		board[row - 1][col].second += tmp;
		count++;
	}
	// 내가 확인하고 있는 미세먼지의 수를 조정합니다.
	board[row][col].second -= tmp * count;
}
int main() {
	int R, C, T;
	std::cin >> R >> C >> T;

	std::pair<int, int>** board = new std::pair<int, int>* [R];
	for (int i = 0; i < R; i++) {
		board[i] = new std::pair<int, int>[C];
	}

	int status;
	std::cin >> status;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> status;
			board[i][j] = std::make_pair(status, 0);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			diffusionInit(board, R, C, i, j);
		}
	}

	for (int i = 0; i < R; i++) {
		delete[] board[i];
	}
	delete[] board;

	return 0;
}