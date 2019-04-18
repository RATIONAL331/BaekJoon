#include<iostream>
#include<vector>
bool checkBoard(std::pair<int, int>** board, int height, int weight, int row, int col) {
	if (row < 0 || col < 0 || row >= height || col >= height) return false;
	if (board[row][col].first < 0) return false;
	return true;
}
void diffusionInit(std::pair<int, int>** board, int height, int weight, int row, int col) {
	if (board[row][col].first < 5) return;
	// �ֺ��� ����
	int count = 0;
	// �̼������� 5�� ���� ����
	int tmp = board[row][col].first / 5;
	
	// �ֺ����� �� �� �ִ� ������ ���� ���մϴ�.
	// �ֺ����� �� �� �ִٸ� 5�γ��� ��ŭ ���մϴ�.
	// ������
	if (checkBoard(board, height, weight, row, col + 1)) {
		board[row][col + 1].second += tmp;
		count++;
	}
	// �Ʒ���
	if (checkBoard(board, height, weight, row + 1, col)) {
		board[row + 1][col].second += tmp;
		count++;
	}
	// ����
	if (checkBoard(board, height, weight, row, col - 1)) {
		board[row][col - 1].second += tmp;
		count++;
	}
	// ����
	if (checkBoard(board, height, weight, row - 1, col)) {
		board[row - 1][col].second += tmp;
		count++;
	}
	// ���� Ȯ���ϰ� �ִ� �̼������� ���� �����մϴ�.
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