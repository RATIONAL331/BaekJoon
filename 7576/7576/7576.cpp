#include<iostream>
#include<queue>
bool boundaryCheck(int Y, int X, int height, int width) {
	if (Y < 0 || X < 0 || Y >= height || X >= width) return false;
	return true;
}
int main() {
	int M, N;
	std::cin >> M >> N;

	std::queue<std::pair<int, int>> bfsQueue;

	int ** board = new int*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[M];
	}

	int state;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> state;
			board[i][j] = state;
			if (state == 1) {
				bfsQueue.push(std::make_pair(i, j));
			}
		}
	}
	
	std::pair<int, int> popInfo;
	int ret = 0;
	while (!bfsQueue.empty()) {
		// 큐에서 정보를 하나씩 뺀다.
		popInfo = bfsQueue.front();
		bfsQueue.pop();

		int popY = popInfo.first;
		int popX = popInfo.second;

		if (boundaryCheck(popY + 1, popX, N, M) && board[popY + 1][popX] == 0) {
			board[popY + 1][popX] = board[popY][popX] + 1;
			bfsQueue.push(std::make_pair(popY + 1, popX));
		}
		if (boundaryCheck(popY, popX + 1, N, M) && board[popY][popX + 1] == 0) {
			board[popY][popX + 1] = board[popY][popX] + 1;
			bfsQueue.push(std::make_pair(popY, popX + 1));
		}
		if (boundaryCheck(popY - 1, popX, N, M) && board[popY - 1][popX] == 0) {
			board[popY - 1][popX] = board[popY][popX] + 1;
			bfsQueue.push(std::make_pair(popY - 1, popX));
		}
		if (boundaryCheck(popY, popX - 1, N, M) && board[popY][popX - 1] == 0) {
			board[popY][popX - 1] = board[popY][popX] + 1;
			bfsQueue.push(std::make_pair(popY, popX - 1));
		}
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				std::cout << -1;
				for (int i = 0; i < N; i++) {
					delete[] board[i];
				}
				delete[] board;
				return 0;
			}
			max = std::max(board[i][j], max);
		}
	}

	std::cout << max - 1;
	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}