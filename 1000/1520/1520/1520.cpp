#include<iostream>
//int calculate(int ** board, int x, int y, int maxWidth, int maxHeight) {
//	if (x < 0 || y < 0) return 0;
//	if (x >= maxWidth || y >= maxHeight) return 0;
//	if (x == maxWidth - 1 && y == maxHeight - 1) return 1;
//	int ret = 0;
//	if (x - 1 >= 0 && board[y][x - 1] < board[y][x]) ret += calculate(board, x - 1, y, maxWidth, maxHeight);
//	if (y - 1 >= 0 && board[y - 1][x] < board[y][x]) ret += calculate(board, x, y - 1, maxWidth, maxHeight);
//	if (x + 1 < maxWidth && board[y][x + 1] < board[y][x]) ret += calculate(board, x + 1, y, maxWidth, maxHeight);
//	if (y + 1 < maxHeight && board[y + 1][x] < board[y][x]) ret += calculate(board, x, y + 1, maxWidth, maxHeight);
//
//	return ret;
//}
int calculate(int ** board, int x, int y, int maxWidth, int maxHeight, int ** dp) {
	if (dp[y][x] != -1) return dp[y][x];
	if (x == maxWidth - 1 && y == maxHeight - 1) return 1;
	// 방문했다면 방문했다고 표시
	dp[y][x] = 0;

	if (x - 1 >= 0 && board[y][x - 1] < board[y][x]) dp[y][x] += calculate(board, x - 1, y, maxWidth, maxHeight, dp);
	if (y - 1 >= 0 && board[y - 1][x] < board[y][x]) dp[y][x] += calculate(board, x, y - 1, maxWidth, maxHeight, dp);
	if (x + 1 < maxWidth && board[y][x + 1] < board[y][x]) dp[y][x] += calculate(board, x + 1, y, maxWidth, maxHeight, dp);
	if (y + 1 < maxHeight && board[y + 1][x] < board[y][x]) dp[y][x] += calculate(board, x, y + 1, maxWidth, maxHeight, dp);
	
	return dp[y][x];
}
int main() {
	int M, N;
	std::cin >> M >> N;
	 //Create Array
	int ** board = new int*[M];
	for (int i = 0; i < M; i++) {
		board[i] = new int[N];
	}
	// Input Board
	int num;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> num;
			board[i][j] = num;
		}
	}
	// Init dp
	int ** dp = new int*[M];
	for (int i = 0; i < M; i++) {
		dp[i] = new int[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	// Calculate Board
	std::cout<<calculate(board, 0, 0, N, M, dp);
	// Delete Array
	for (int i = 0; i < M; i++) {
		delete[] dp[i];
	}
	delete[] dp;
	for (int i = 0; i < M; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}
