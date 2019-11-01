#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, T;

const int INF_MIN = INT32_MIN;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

void changeAdjacent(vector<deque<int>>& circle, int order, int pos, bool& isAdj) {
	vector<vector<bool>> visited(N);
	for (int i = 0; i < N; i++) 
		visited[i].resize(M);

	queue<pair<int, int>> que;
	que.push({ order, pos });
	bool isChange = false;

	visited[order][pos] = true;
	int cmpNum = circle[order][pos];

	while (!que.empty()) {
		int popOrder = que.front().first;
		int popPos = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int newOrder = popOrder + dy[i];
			int newPos = popPos + dx[i];

			if (newOrder < 0 || newOrder >= N) continue;
			newPos = newPos < 0 ? M - 1 : newPos >= M ? 0 : newPos;

			if (visited[newOrder][newPos] == false && circle[newOrder][newPos] == cmpNum) {
				visited[newOrder][newPos] = true;
				que.push({ newOrder, newPos });
				circle[newOrder][newPos] = INF_MIN;
				
				isChange = true;
			}
		}		
	}

	if (isChange == true) {
		circle[order][pos] = INF_MIN;
		isAdj = true;
	}		
}

void checkAdjacent(vector<deque<int>>& circle, bool& isAdj) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(circle[i][j] != INF_MIN)
				changeAdjacent(circle, i, j, isAdj);
		}
	}
}

pair<int, int> getSumAndCnt(vector<deque<int>>& circle) {
	int sum = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != INF_MIN) {
				sum += circle[i][j];
				cnt++;
			}
		}
	}
	return { sum, cnt };
}

void avgPlusMinus(vector<deque<int>>& circle, double avg) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != INF_MIN) {
				if (circle[i][j] > avg)
					circle[i][j] -= 1;
				else if (circle[i][j] < avg)
					circle[i][j] += 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	/* INIT Phase */
	cin >> N >> M >> T;

	vector<deque<int>> circle(N);

	int number;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> number;
			circle[i].push_back(number);
		}
	}
	/* SOLVE Phase */
	/* x의 배수 원판을 d의 방향으로(0은 시계, 1은 반시계) k번 회전*/
	int x; bool d; int k;
	while (T--) {
		cin >> x >> d >> k;
		for (int i = 1; i * x <= N; i++) {
			int multiple_x = i * x - 1;
			for(int rotate = 0; rotate < k; rotate++) {
				if (d == 0) {
					int tmp = circle[multiple_x].back();
					circle[multiple_x].pop_back();
					circle[multiple_x].push_front(tmp);
				}
				else {
					int tmp = circle[multiple_x].front();
					circle[multiple_x].pop_front();
					circle[multiple_x].push_back(tmp);
				}

			}
		}
		bool isAdjacent = false;
		checkAdjacent(circle, isAdjacent);
		if (isAdjacent == false) {
			double avg;
			pair<int, int> sumAndCnt = getSumAndCnt(circle);
			if (sumAndCnt.second != 0)
				avg = (double)sumAndCnt.first / sumAndCnt.second;
			else avg = 0;

			avgPlusMinus(circle, avg);
		}
	}

	/* PRINT Phase */
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		if (circle[i][j] == INF_MIN)
	//			cout << "DEL" << " ";
	//		else cout << circle[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	pair<int, int> result = getSumAndCnt(circle);
	cout << result.first;

	return 0;
}