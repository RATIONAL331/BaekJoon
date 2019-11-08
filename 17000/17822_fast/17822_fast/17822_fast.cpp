#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, T;

int SUM;
int CNT;

const int INF_MIN = INT32_MIN;

void checkAdjacent(vector<deque<int>>& circle) {
	vector<vector<bool>> isDel(N);
	for (int i = 0; i < N; i++) 
		isDel[i].resize(M);

	bool isChange = false;

	/* 1. 양 옆으로 확인 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (circle[i][j] != INF_MIN && circle[i][j + 1] != INF_MIN && circle[i][j] == circle[i][j + 1]) {
				isDel[i][j] = true;
				isDel[i][j + 1] = true;
				isChange = true;
			}
		}
		if (circle[i][0] != INF_MIN && circle[i][M - 1] != INF_MIN && circle[i][0] == circle[i][M - 1]) {
			isDel[i][0] = true;
			isDel[i][M - 1] = true;
			isChange = true;
		}
	}
	/* 2. 위 아래로 확인 */
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N - 1; i++) {
			if (circle[i][j] != INF_MIN && circle[i + 1][j] != INF_MIN && circle[i][j] == circle[i + 1][j]) {
				isDel[i][j] = true;
				isDel[i + 1][j] = true;
				isChange = true;
			}
		}
	}

	if (isChange == true) {
		/* 3. 변경되었으면 삭제하기 */
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[i][j] != INF_MIN && isDel[i][j] == true) {
					SUM -= circle[i][j];
					CNT--;
					circle[i][j] = INF_MIN;
				}
			}
		}
	}
	else {
		/* 4. 변경 안됬으면 평균 구하고 +1, -1과정 거치기 */
		double AVG = (double)SUM / CNT;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[i][j] != INF_MIN) {
					if (circle[i][j] > AVG) {
						circle[i][j] -= 1;
						SUM--;
					}
					else if(circle[i][j] < AVG) {
						circle[i][j] += 1;
						SUM++;
					}
				}
			}
		}
	}
}

void print(vector<deque<int>>& circle) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != INF_MIN)
				cout << circle[i][j] << " ";
			else cout << "DEL" << " ";
		}
		cout << endl;
	}
}

int main() {
	/* INIT Phase */
	cin >> N >> M >> T;

	vector<deque<int>> circle(N);

	int number;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> number;
			SUM += number;
			CNT++;
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
			for (int rotate = 0; rotate < k; rotate++) {
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
		checkAdjacent(circle);	
		//print(circle);
	}

	/* PRINT Phase */
	cout << SUM;

	return 0;
}