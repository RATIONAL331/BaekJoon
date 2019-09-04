#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
int main() {
	int T;
	std::cin >> T;

	int N, L, K;
	for (int i = 0; i < T; i++) {
		std::cin >> N >> L >> K;
		std::vector<std::pair<int, int>> ant(N);
		std::vector<std::pair<int, int>> result(N);
		std::deque<int> andId;

		int p, a;
		for (int j = 0; j < N; j++) {
			std::cin >> p >> a; // p = 위치 및 거리, a = ID
			a < 0 ? ant[j].first = p : ant[j].first = L - p; // ID가 음수이면 원래 이동할 거리는 p, ID가 양수면 원래 이동할 거리는 L - p
			ant[j].second = a;
			andId.push_back(a);
		}
		std::sort(ant.begin(), ant.end()); // 이동할 거리를 오름차순으로 정렬
		for (int j = 0; j < N; j++) {
			result[j].first = ant[j].first;
			if (ant[j].second > 0) { result[j].second = andId.back(); andId.pop_back(); } // 꺼냈을 때, ID가 양수면 맨 끝 원소를
			else { result[j].second = andId.front(); andId.pop_front(); } // 꺼냈을 때, ID가 음수면 맨 앞쪽 원소를 지정
		}
		std::sort(result.begin(), result.end());
		std::cout << result.at(K - 1).second << std::endl;
	}
	return 0;
}