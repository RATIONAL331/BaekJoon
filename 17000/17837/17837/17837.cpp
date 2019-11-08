#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, K;
struct horse {
	int row, col, dir;
};
// 1. <-, 2. ->, 3. ^, 4. v;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { 1, -1, 0, 0 };
const int newDir[] = { 1, 0, 3, 2 };

// (게임 판에 어떤 말이 올라와 있는지에 대한 정보, 색)
vector<vector<pair<vector<int>, int>>> horseBoard;
// 말에 대한 정보
vector<horse> horseVec;

int moveHorse(int horseNum) {
	int curRow = horseVec[horseNum].row;
	int curCol = horseVec[horseNum].col;
	int nextRow = curRow + dx[horseVec[horseNum].dir];
	int nextCol = curCol + dy[horseVec[horseNum].dir];

	if (nextRow < 0 || nextRow >= N ||
		nextCol < 0 || nextCol >= N ||
		horseBoard[nextRow][nextCol].second == 2) {
		horseVec[horseNum].dir = newDir[horseVec[horseNum].dir];

		nextRow = curRow + dx[horseVec[horseNum].dir];
		nextCol = curCol + dy[horseVec[horseNum].dir];

		if (nextRow < 0 || nextRow >= N ||
			nextCol < 0 || nextCol >= N ||
			horseBoard[nextRow][nextCol].second == 2)
			return horseBoard[curRow][curCol].first.size();
	}

	vector<int>& cur = horseBoard[curRow][curCol].first;
	vector<int>& next = horseBoard[nextRow][nextCol].first;

	auto findIter = find(cur.begin(), cur.end(), horseNum);
	if (horseBoard[nextRow][nextCol].second == 1)
		reverse(findIter, cur.end());

	for (auto iter = findIter; iter != cur.end(); iter++) {
		horseVec[*iter].row = nextRow;
		horseVec[*iter].col = nextCol;
		next.push_back(*iter);
	}

	cur.erase(findIter, cur.end());
	return next.size();
}

int main(){
	/* INIT Phase */
	cin >> N >> K;
	horseBoard.resize(N);
	for (int i = 0; i < N; i++) horseBoard[i].resize(N);

	horseVec.resize(K);
	
	int color;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> color;
			horseBoard[i][j].second = color;
		}
	}

	int row, col, dir;
	for (int i = 0; i < K; ++i) {
		cin >> row >> col >> dir;
		horseVec[i].row = row - 1;
		horseVec[i].col = col - 1;
		horseVec[i].dir = dir - 1;
		horseBoard[row - 1][col - 1].first.push_back(i);
	}

	/* SOLVE Phase */
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < K; j++) {
			if (moveHorse(j) >= 4) {
				cout << i;
				return 0;
			}
		}
	}

	cout << -1;
	return 0;
}