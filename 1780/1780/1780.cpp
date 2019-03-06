#include<iostream>
bool arrSame(int** board, int y, int x, int height, int what) {
	for (int i = y; i < y + height; i++) {
		for (int j = x; j < x + height; j++) {
			if (what != board[i][j]) { return false; }
		}
	}
	return true;
}
int isAllSame(int** board, int y , int x, int height, int what) {
	if (height < 1) return 0;
	if (arrSame(board, y, x, height, what)) return 1;
	else {
		int ret = 0;

		ret += isAllSame(board, y, x, height / 3, what);
		ret += isAllSame(board, y, x + height / 3, height / 3, what);
		ret += isAllSame(board, y, x + 2 * (height / 3), height / 3, what);

		ret += isAllSame(board, y + height / 3, x, height / 3, what);
		ret += isAllSame(board, y + height / 3, x + height / 3, height / 3, what);
		ret += isAllSame(board, y + height / 3, x + 2 * (height / 3), height / 3, what);

		ret += isAllSame(board, y + 2 * (height / 3), x, height / 3, what);
		ret += isAllSame(board, y + 2 * (height / 3), x + height / 3, height / 3, what);
		ret += isAllSame(board, y + 2 * (height / 3), x + 2 * (height / 3), height / 3, what);
		
		return ret;
	}
}
int main() {
	int N;
	std::cin >> N;

	int ** board = new int*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[N];
	}

	int count;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> count;
			board[i][j] = count;
		}
	}
	for (int i = -1; i <= 1; i++) {
		std::cout << isAllSame(board, 0, 0, N, i) << std::endl;
	}
	
	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}