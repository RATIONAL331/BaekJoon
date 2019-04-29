#include<iostream>
int countBoard(std::pair<int, int>** board, int height, int width) {
	int count = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			count += board[i][j].first;
		}
	}
	return count;
}
bool checkBoard(std::pair<int, int>** board, int height, int width, int row, int col) {
	if (row < 0 || col < 0 || row >= height || col >= width) return false;
	if (board[row][col].first < 0) return false;
	return true;
}
void diffusionInit(std::pair<int, int>** board, int height, int width, int row, int col) {
	if (board[row][col].first < 5) return;
	// �ֺ��� ����
	int count = 0;
	// �̼������� 5�� ���� ����
	int tmp = board[row][col].first / 5;
	
	// �ֺ����� �� �� �ִ� ������ ���� ���մϴ�.
	// �ֺ����� �� �� �ִٸ� 5�γ��� ��ŭ ���մϴ�.
	// ������
	if (checkBoard(board, height, width, row, col + 1)) {
		board[row][col + 1].second += tmp;
		count++;
	}
	// �Ʒ���
	if (checkBoard(board, height, width, row + 1, col)) {
		board[row + 1][col].second += tmp;
		count++;
	}
	// ����
	if (checkBoard(board, height, width, row, col - 1)) {
		board[row][col - 1].second += tmp;
		count++;
	}
	// ����
	if (checkBoard(board, height, width, row - 1, col)) {
		board[row - 1][col].second += tmp;
		count++;
	}
	// ���� Ȯ���ϰ� �ִ� �̼������� ���� �����մϴ�.
	board[row][col].second -= tmp * count;
}
void diffusionStart(std::pair<int, int>** board, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j].first != -1) {
				board[i][j].first = board[i][j].first + board[i][j].second;
				board[i][j].second = 0;
			}
		}
	}
}

void moveArray(std::pair<int, int>** board, int pivot, bool isUp, int height, int width) {
	// ���� ��ȯ
	if (isUp) {
		for (int i = pivot - 1; i >= 1; i--) {
			board[i][0] = board[i - 1][0];
		}
		for (int i = 0; i < width - 1; i++) {
			board[0][i] = board[0][i + 1];
		}
		for (int i = 0; i <= pivot - 1; i++) {
			board[i][width - 1] = board[i + 1][width - 1];
		}
		for (int i = width - 1; i > 1; i--) {
			board[pivot][i] = board[pivot][i - 1];
		}
		board[pivot][1].first = 0;
	}
	// �Ʒ��� ��ȯ
	else {
		for (int i = pivot + 1; i < height - 1; i++) {
			board[i][0] = board[i + 1][0];
		}
		for (int i = 0; i < width - 1; i++) {
			board[height - 1][i] = board[height - 1][i + 1];
		}
		for (int i = height - 1; i > pivot; i--) {
			board[i][width - 1] = board[i - 1][width - 1];
		}
		for (int i = width - 1; i > 1; i--) {
			board[pivot][i] = board[pivot][i - 1];
		}
		board[pivot][1].first = 0;
	}
}
int main() {
	int R, C, T;
	std::cin >> R >> C >> T;

	std::pair<int, int>** board = new std::pair<int, int>* [R];
	for (int i = 0; i < R; i++) {
		board[i] = new std::pair<int, int>[C];
	}

	bool up = false;
	int status;
	int upIndex = -1;
	int downIndex = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> status;
			board[i][j] = std::make_pair(status, 0);
			if (status == -1) { 
				if (!up)
					{upIndex = i; up = true;}
				else
					downIndex = i;
			}
			
		}
	}
	while (T--) {
		// 1. Ȯ���� �̷������.
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				diffusionInit(board, R, C, i, j);
			}
		}
		diffusionStart(board, R, C);
		// 2. ��ȯ�Ǹ� ��ȭ�ȴ�.
		// 2.1 ���� ��ȯ
		moveArray(board, upIndex, true, R, C);
		// 2.2 �Ʒ��� ��ȯ
		moveArray(board, downIndex, false, R, C);
	}
	
	std::cout << countBoard(board, R, C) + 2;

	for (int i = 0; i < R; i++) {
		delete[] board[i];
	}
	delete[] board;

	return 0;
}