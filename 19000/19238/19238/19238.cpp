#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[] = { 0, -1, 1, 0 };
const int dx[] = { -1, 0, 0, 1 };

struct Position {
	int x, y;
	bool operator<(const Position& obj) const {
		if (this->x == obj.x) return this->y <= obj.y;
		else return this->x < obj.x;
	}
};

struct Passenger {
	Position start, dest;
};

struct Info {
	int idx, distance;
};

vector<vector<int>> board;
vector<Passenger> passengers;
Position taxi;
int N, M, initGas;

Info findPassenger() {
	int idx = 0, distance = 0;
	if (board[taxi.x][taxi.y] > 0) {
		idx = board[taxi.x][taxi.y];
		board[taxi.x][taxi.y] = 0;
		return { idx, 0 };
	}
	queue<Position> que;
	vector<Position> candidate;

	vector<vector<bool>> visited;
	visited.resize(N);
	for (int i = 0; i < N; i++)
		visited[i].resize(N);

	que.push(taxi);
	visited[taxi.x][taxi.y] = true;

	while (!que.empty()) {
		distance++;
		if (initGas - distance < 0) return { -1, -1 };

		int size = que.size();
		bool flag = false;

		while (size--) {
			Position now = que.front(); que.pop();
			for (int i = 0; i < 4; ++i) {
				int nextX = now.x + dx[i];
				int nextY = now.y + dy[i];
				if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
				if (board[nextX][nextY] >= 0 && !visited[nextX][nextY]) {
					visited[nextX][nextY] = true;
					que.push({ nextX, nextY });
					if (board[nextX][nextY] > 0) {
						candidate.push_back({ nextX, nextY });
						flag = true;
					}
				}
			}
		}
		if (flag) {
			sort(candidate.begin(), candidate.end());
			taxi = candidate[0];
			idx = board[candidate[0].x][candidate[0].y];
			board[candidate[0].x][candidate[0].y] = 0;
			return { idx, distance };
		}
	}
	return { -1, -1 };
}

int sendPassenger(int idx) {
	idx -= 1;
	vector<vector<bool>> visited;
	visited.resize(N);
	for (int i = 0; i < N; i++)
		visited[i].resize(N);

	queue<Position> que;
	que.push(taxi);
	visited[taxi.x][taxi.y] = true;
	Position dest = passengers[idx].dest;
	int distance = 0;

	while (!que.empty()) {
		distance++;
		if (initGas - distance < 0) return -1;

		int size = que.size();
		while (size--) {
			Position now = que.front(); que.pop();
			for (int i = 0; i < 4; ++i) {
				int nextX = now.x + dx[i];
				int nextY = now.y + dy[i];
				if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
				if (board[nextX][nextY] == -1 || visited[nextX][nextY]) continue;
				if (nextX == dest.x && nextY == dest.y) {
					taxi = dest;
					return distance;
				}
				visited[nextX][nextY] = true;
				que.push({ nextX, nextY });
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M >> initGas;
	board.resize(N);
	passengers.resize(M);
	for (int i = 0; i < N; i++)
		board[i].resize(N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			board[i][j] *= -1;
		}
	}

	cin >> taxi.x >> taxi.y;
	--taxi.x; --taxi.y;

	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		passengers[i] = { { x1 - 1, y1 - 1 }, { x2 - 1, y2 - 1 } };
		board[x1 - 1][y1 - 1] = i + 1;
	}

	while (M--) {
		Info info = findPassenger();
		initGas -= info.distance;
		if (info.idx == -1 || initGas < 0) {
			initGas = -1;
			break;
		}

		int distance = sendPassenger(info.idx);
		initGas -= distance;
		if (distance == -1 || initGas < 0) {
			initGas = -1;
			break;
		}
		initGas += distance * 2;
	}

	cout << initGas;
	return 0;
}