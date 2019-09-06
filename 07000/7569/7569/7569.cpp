#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct Point {
	int x, y, z;
};
int main() {
	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> board;
	board.resize(H);
	for (int i = 0; i < H; i++) {
		board[i].resize(N);
		for (int j = 0; j < N; j++) {
			board[i][j].resize(M);
		}
	}

	int zeroCount = 0;
	queue<Point> q;

	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> board[h][n][m];
				if (board[h][n][m] == 1) 
					q.push({ m, n, h });
				else if (board[h][n][m] == 0)
					zeroCount++;
			}
		}
	}
	
	if (zeroCount == 0) {
		printf("0"); return 0;
	}
	int dx[] = {1, 0, -1, 0, 0, 0};
	int dy[] = {0, 1, 0, -1, 0, 0};
	int dz[] = {0, 0, 0, 0, 1, -1};

	int maxValue = 1;
	while (!q.empty()) {
		auto elem = q.front(); q.pop();
		int xpos = elem.x; int ypos = elem.y; int zpos = elem.z;
		for (int i = 0; i < 6; i++) {
			if (xpos + dx[i] >= 0 && xpos + dx[i] < M
				&& ypos + dy[i] >= 0 && ypos + dy[i] < N
				&& zpos + dz[i] >= 0 && zpos + dz[i] < H
				&& board[zpos + dz[i]][ypos + dy[i]][xpos + dx[i]] == 0) {

				board[zpos + dz[i]][ypos + dy[i]][xpos + dx[i]] = board[zpos][ypos][xpos] + 1;
				q.push({ xpos + dx[i], ypos + dy[i], zpos + dz[i] });
				maxValue = max(maxValue, board[zpos + dz[i]][ypos + dy[i]][xpos + dx[i]]);
				zeroCount--;
			}
		}
	}
	if (zeroCount == 0) {
		cout << maxValue - 1;
	}
	else cout << -1;
	return 0;
}