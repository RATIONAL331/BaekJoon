#include<iostream>
void squarring(char** board, int height, int x, int y) {
	if (height == 1) {
		board[y][x] = '*';
		return;
	}
	if (height == 3) {
		board[y][x] = '*';
		board[y][x + 1] = '*';
		board[y][x + 2] = '*';
		board[y + 1][x] = '*';
		board[y + 1][x + 2] = '*';
		board[y + 2][x] = '*';
		board[y + 2][x + 1] = '*';
		board[y + 2][x + 2] = '*';
		return;
	}
	squarring(board, height / 3, x, y);
	squarring(board, height / 3, x + (height / 3), y);
	squarring(board, height / 3, x + 2 * (height / 3), y);
	squarring(board, height / 3, x, y + (height / 3));
	squarring(board, height / 3, x + 2 * (height / 3), y + (height / 3));
	squarring(board, height / 3, x, y + 2 * (height / 3));
	squarring(board, height / 3, x + (height / 3), y + 2 * (height / 3));
	squarring(board, height / 3, x + 2 * (height / 3), y + 2 * (height / 3));
}
int main() {
	int N;
	std::cin >> N;

	char ** board = new char*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new char[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = ' ';
		}
	}

	squarring(board, N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}