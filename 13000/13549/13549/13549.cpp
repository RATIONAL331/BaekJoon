#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N, K;
bool visited[100'001];

int solve(int here) {
	queue<pair<int, int>> que;
	que.push({ here, 0 });
	visited[here] = true;

	int minValue = 987654321;

	while (!que.empty()) {
		int popElem = que.front().first;
		int popCnt = que.front().second;
		que.pop();

		if (popElem == K)
			return popCnt;	

		if (popElem * 2 <= 100000 && !visited[popElem * 2]) {
			que.push({ popElem * 2, popCnt });
			visited[N] = true;
		}
		if (popElem - 1 >= 0 && !visited[popElem - 1]) {
			que.push({ popElem - 1, popCnt + 1 });
			visited[popElem - 1] = true;
		}
		if (popElem + 1 <= 100000 && !visited[popElem + 1]) {
			que.push({ popElem + 1, popCnt + 1 });
			visited[N] = true;
		}
	}
	return minValue;
}

int main() {
	cin >> N >> K;
	cout << solve(N);
	return 0;
}