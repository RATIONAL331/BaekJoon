#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> vec(N);
	int startTime, endTime;
	for (int i = 0; i < N; i++) {
		cin >> startTime >> endTime;
		vec[i] = { startTime, endTime };
	}

	sort(vec.begin(), vec.end(), [](auto a, auto b)->bool {
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
		});

	int select = 0;
	int cnt = 0;
	for (auto& elem : vec) {
		if (select <= elem.first) {
			select = elem.second;
			cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}