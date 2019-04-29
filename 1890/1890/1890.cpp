#include<iostream>
using namespace std;
int N;
int board[100][100];
long long dp[100][100] = { 0, };

long long dfs(int curX, int curY) {
	if (curX < 0 || curX >= N || curY < 0 || curY >= N) return 0;
	if (dp[curY][curX] > 0) return dp[curY][curX];
	if (curY == N - 1 && curX == N - 1) return dp[curY][curX] = 1;
	if (board[curY][curX] == 0) return 0;

	int tmp = board[curY][curX];
	dp[curY][curX] = dfs(curX + tmp, curY) + dfs(curX, curY + tmp);
	return dp[curY][curX];
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	cout << dfs(0, 0);

	return 0;
}