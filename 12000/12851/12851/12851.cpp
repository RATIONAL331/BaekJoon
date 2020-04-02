#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N, K;
bool visited[100001];

pair<int, int> solve() {
	queue<pair<int, int>> que;
	que.push({ N, 0 });

	int cnt = 0;
	int findValue = INT32_MAX;

	while (!que.empty()) {
		int popElem = que.front().first;
		int popElemSecond = que.front().second;
		que.pop();

		visited[popElem] = true;

		if (popElemSecond > findValue)
			break;
		if (popElem == K && popElemSecond <= findValue) {
			findValue = popElemSecond;
			cnt++;
		}

		if (popElem - 1 >= 0 && !visited[popElem - 1]) 
			que.push({ popElem - 1, popElemSecond + 1 });
		if (popElem + 1 <= 100000 && !visited[popElem + 1])
			que.push({ popElem + 1, popElemSecond + 1 });
		if (popElem * 2 <= 100000 && !visited[popElem * 2])
			que.push({ popElem * 2, popElemSecond + 1 });
	}
	return { findValue, cnt };
}

int main() {
	cin >> N >> K;
	if (N == K) {
		cout << 0 << '\n' << 1;
		return 0;
	}
	auto ret = solve();
	cout << ret.first << '\n' << ret.second;

	return 0;
}