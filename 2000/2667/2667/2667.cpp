#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
void dfs(bool** board, int weight, int height, int curX, int curY, int* cnt) {
	if (curX < 0 || curY < 0 || curX >= weight || curY >= height) return;
	if (board[curY][curX] == 0) return;

	board[curY][curX] = 0;
	*cnt = *cnt + 1;

	dfs(board, weight, height, curX + 1, curY, cnt);
	dfs(board, weight, height, curX, curY + 1, cnt);
	dfs(board, weight, height, curX - 1, curY, cnt);
	dfs(board, weight, height, curX, curY - 1, cnt);
}
int main() {
	int N;
	std::cin >> N;

	bool ** board = new bool*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new bool[N];
	}

	std::string line;
	for (int i = 0; i < N; i++) {
		std::cin >> line;
		for (int j = 0; j < N; j++) {
			board[i][j] = line.at(j) - '0';
		}
	}

	int cnt;
	int ret = 0;
	std::vector<int> cntVec;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 0;
			if (board[i][j] == 1) {
				dfs(board, N, N, j, i, &cnt);
				ret++;
				cntVec.push_back(cnt);
			}
		}
	}
	std::sort(cntVec.begin(), cntVec.end());

	std::cout << ret << std::endl;
	for (int i : cntVec) {
		std::cout << i << std::endl;
	}

	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}