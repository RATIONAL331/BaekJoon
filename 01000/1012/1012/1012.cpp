/*
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5
*/

#include<iostream>
#include<vector>
using namespace std;

int T, M, N, K;
bool board[51][51];
void dfs(int Y, int X) {
	if (Y < 0 || Y >= N || X < 0 || X >= M) return;
	if (!board[Y][X]) return;
	
	board[Y][X] = false;
	dfs(Y - 1, X);
	dfs(Y, X + 1);
	dfs(Y + 1, X);
	dfs(Y, X - 1);
}
int main() {
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;

		int X, Y;
		while(K--) {
			cin >> X >> Y;
			board[Y][X] = true;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}