#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> queryBoard;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	board.resize(N);
	queryBoard.resize(N + 1);
	for (int i = 0; i < N; i++) {
		board[i].resize(M);
		queryBoard[i].resize(M + 1);
	}
	queryBoard[N].resize(M + 1);
		
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			queryBoard[i + 1][j + 1] = board[i][j];
			if (i != 0 && j != 0) {
				queryBoard[i + 1][j + 1] += queryBoard[i + 1][j];
				queryBoard[i + 1][j + 1] += queryBoard[i][j + 1];
				queryBoard[i + 1][j + 1] -= queryBoard[i][j];
			}
			else if (i == 0 && j != 0)
				queryBoard[i + 1][j + 1] += queryBoard[i + 1][j];
			else if (i != 0 && j == 0)
				queryBoard[i + 1][j + 1] += queryBoard[i][j + 1];
		}
	}

	int K;
	cin >> K;

	int i, j, x, y;
	while (K--) {
		cin >> i >> j >> x >> y;
		cout << queryBoard[x][y] + queryBoard[i - 1][j - 1] 
				- queryBoard[x][j - 1] - queryBoard[i - 1][y] << '\n';
	}

	return 0;
}