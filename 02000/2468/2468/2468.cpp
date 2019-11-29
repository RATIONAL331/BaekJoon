#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct position {
	int y, x, h;
	bool operator<(const position& obj) const {
		return this->h > obj.h;
	}
};

int N;
vector<position> board;

vector<int> unionFind;
vector<bool> check;

int groupCount;
int maxCount;
				 /* >  v  <  ^ */
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int finding(int x) {
	if (x == unionFind[x]) return x;
	return unionFind[x] = finding(unionFind[x]);
}

void unioning(int p, int q) {
	p = finding(p);
	q = finding(q);

	if (p != q) {
		// p의 집합을 q에 연결
		unionFind[p] = q;
		groupCount--;
	}
}

int getIdx(position& point) {
	return point.y * N + point.x;
}

int main() {
	cin >> N;

	board.resize(N);

	int H;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> H;
			board.push_back({ i, j, H });
		}
	}
	sort(board.begin(), board.end());

	unionFind.resize(N * N);
	check.resize(N * N);

	int cnt = 0;

	for (int i = 0; i < N * N; i++)
		unionFind[i] = i;

	for (int i = 0, next; i < board.size() - 1; i = next)
	{
		// 다음 높이 인덱스 찾기
		for (next = i; next < board.size() && board[i].y == board[next].y; next++);
		for (int j = i; j < next; j++)
		{
			check[getIdx(board[j])] = true;
			groupCount++;
			for (int k = 0; k < 4; k++)
			{
				int nextY = board[j].y + dy[k];
				int nextX = board[j].x + dx[k];
				if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N) {
					if (check[nextY * N + nextX]) {
						unioning(getIdx(board[j]), nextY * N + nextX);
					}
				}
			}
		}
		maxCount = max(maxCount, groupCount);
	}

	cout << maxCount;


	return 0;
}