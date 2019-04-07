#include<iostream>
#include<algorithm>
#include<string>
void visit(int** board, int curY, int curX, int height, int weight, int beforeElem) {
	if (curY < 0 || curY >= height || curX < 0 || curX >= weight) {
		return;
	}
	if (board[curY][curX] == 0) {
		return;
	}

	if (board[curY][curX] > 1) {
		board[curY][curX] = std::min(board[curY][curX], beforeElem + 1);
		return;
	}

	if (board[curY][curX] == 1){
		board[curY][curX] += beforeElem;
	}

	visit(board, curY + 1, curX, height, weight, board[curY][curX]);
	visit(board, curY, curX + 1, height, weight, board[curY][curX]);
	visit(board, curY - 1, curX, height, weight, board[curY][curX]);
	visit(board, curY, curX - 1, height, weight, board[curY][curX]);

}
int main() {
	int N, M;
	std::cin >> N >> M;

	int** board = new int*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[M];
	}

	std::string input;
	for (int i = 0; i < N; i++) {
		std::cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input.at(j) - '0';
		}
	}

	visit(board, 0, 0, N, M, 0);
	std::cout<<board[N - 1][M - 1];

	return 0;
}