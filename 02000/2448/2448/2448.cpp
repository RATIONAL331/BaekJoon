#include<iostream>
void starring(char** board, int height, int x, int y) {
	if (height == 3) {
		board[y][x] = '*';
		board[y + 1][x - 1] = '*';
		board[y + 1][x + 1] = '*';
		board[y + 2][x - 2] = '*';
		board[y + 2][x - 1] = '*';
		board[y + 2][x] = '*';
		board[y + 2][x + 1] = '*';
		board[y + 2][x + 2] = '*';
		return;
	}
	starring(board, height / 2, x, y); //À­ºÎºÐ
	starring(board, height / 2, x - (height / 2), y + (height / 2)); //¾Æ·§ºÎºÐ ¿ÞÂÊ
	starring(board, height / 2, x + (height / 2), y + (height / 2)); //¾Æ·§ºÎºÐ ¿À¸¥ÂÊ
}

int main() {
	int n;
	std::cin >> n;
	char ** board = new char*[n];
	for (int i = 0; i < n; i++) {
		board[i] = new char[n * 2];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			board[i][j] = ' ';
		}
	}

	starring(board, n, n - 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}


	for (int i = 0; i < n; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}