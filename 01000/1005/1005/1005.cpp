#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	int N, K, W;
	while (T--) {
		cin >> N >> K;

		vector<bool> visitList(N);
		vector<int> degreeList(N);
		vector<pair<vector<int>, int>> graph(N);
		vector<int> cost(N);

		for (int i = 0; i < N; i++)
			cin >> cost[i];

		int X, Y;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			graph[X - 1].first.push_back(Y - 1);
			degreeList[Y - 1]++;
		}

		queue<int> readyQ;
		for (int i = 0; i < N; i++) {
			graph[i].second = cost[i];
			if (degreeList[i] == 0) {
				readyQ.push(i);
				visitList[i] = true;
			}
		}

		bool finish = false;
		cin >> W;
		while (!readyQ.empty() && finish == false) {
			int popNode = readyQ.front(); readyQ.pop();
			int beforeSavedCost = graph[popNode].second;
			for (int& popElem : graph[popNode].first) {
				degreeList[popElem]--;

				int& savedCost = graph[popElem].second;
				savedCost = max(savedCost, beforeSavedCost + cost[popElem]);

				if (visitList[popElem] == false && degreeList[popElem] == 0) {
					visitList[popElem] = true;
					readyQ.push(popElem);
					if (popElem == W - 1) {
						finish = true;
						break;
					}
				}
			}
		}
		cout << graph[W - 1].second << endl;
	}
	return 0;
}