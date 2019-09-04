#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
bool checkLine(int** board, int weight, int height, int curX, int curY) {
	if (curX < 0 || curY < 0 || curX >= weight || curY >= height) return false;
	if (board[curY][curX] == 0) return false;
	return true;
}
void bfs(int** board, int weight, int height, int curX, int curY) {
	if (!checkLine(board, weight, height, curX, curY)) return;
	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(curX, curY));

	std::pair<int, int> popElem;
	while (!queue.empty()) {
		popElem = queue.front();
		queue.pop();
		
		int popX = popElem.first;
		int popY = popElem.second;

		// 아래쪽
		if (checkLine(board, weight, height, popX, popY + 1) && board[popY + 1][popX] == 1) {
			board[popY + 1][popX] = board[popY][popX] + 1;
			queue.push(std::make_pair(popX, popY + 1));
		}
		// 오른쪽
		if (checkLine(board, weight, height, popX + 1, popY) && board[popY][popX + 1] == 1) {
			board[popY][popX + 1] = board[popY][popX] + 1;
			queue.push(std::make_pair(popX + 1, popY));
		}
		// 위쪽
		if (checkLine(board, weight, height, popX, popY - 1) && board[popY - 1][popX] == 1) {
			board[popY - 1][popX] = board[popY][popX] + 1;
			queue.push(std::make_pair(popX, popY - 1));
		}
		// 왼쪽
		if (checkLine(board, weight, height, popX - 1, popY) && board[popY][popX  - 1] == 1) {
			board[popY][popX - 1] = board[popY][popX] + 1;
			queue.push(std::make_pair(popX - 1, popY));
		}
	}
	
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
	bfs(board, M, N, 0, 0);

	std::cout<<board[N - 1][M - 1];

	return 0;
}