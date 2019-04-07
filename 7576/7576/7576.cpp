#include<iostream>
int main() {
	int M, N;
	std::cin >> M >> N;
	
	int ** board = new int*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[M];
	}

	int state;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> state;
			board[i][j] = state;
		}
	}

	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}