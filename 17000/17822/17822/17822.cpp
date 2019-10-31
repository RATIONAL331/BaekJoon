#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
	/* INIT Phase */
	int N, M, T;
	cin >> N >> M >> T;

	vector<deque<int>> circle(N + 1);

	int number;
	for (int i = 1; i <= N; i++) {
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
			int multiple_x = i * x;
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
	}

	/* PRINT Phase */
	for (int i = 1; i <= N; i++) {
		for (const auto& elem : circle[i]) {
			cout << elem << " ";
		}
		cout << endl;
	}

	return 0;
}