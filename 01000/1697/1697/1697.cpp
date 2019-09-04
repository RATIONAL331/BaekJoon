//#include<iostream>
//#include<queue>
//using namespace std;
//
//bool visited[100001];
//int bfs(int N, int K) {
//	queue<pair<int, int>> q;
//	q.push({ N, 0 });
//	visited[N] = true;
//	
//	while (!q.empty()) {
//		auto popelem = q.front(); q.pop();
//		int curPos = popelem.first;
//		int curTime = popelem.second;
//		
//		if (curPos == K) return curTime;
//		
//		if (curPos + 1 <= 100000 && !visited[curPos + 1]) {
//			visited[curPos + 1] = true;
//			q.push({ curPos + 1, curTime + 1 });
//		}
//		if (curPos - 1 >= 0 && !visited[curPos - 1]) {
//			visited[curPos - 1] = true;
//			q.push({ curPos - 1, curTime + 1 });
//		}
//		if (curPos * 2 <= 100000 && !visited[curPos * 2]) {
//			visited[curPos * 2] = true;
//			q.push({ curPos * 2, curTime + 1 });
//		}
//	}
//	return 987654321;
//}
//
//int main() {
//	int N, K;
//	cin >> N >> K;
//	cout << bfs(N, K);
//	return 0;
//}

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dp[100001];

int solve(int N, int K) {
	int& ret = dp[N];
	if (ret != -1) return ret;

	if (N < 0) return 987654321;
	if (N > 100000) return 987654321;

	if (N == K) return ret = 0;
	ret = N - K;
	if (N < K) {
		
	}
	else return ret = N - K;
}

int main() {
	int N, K;
	cin >> N >> K;

	fill(begin(dp), end(dp), -1);
	cout << solve(N, K);

	return 0;
}