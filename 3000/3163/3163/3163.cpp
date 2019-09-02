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
			std::cin >> p >> a; // p = ��ġ �� �Ÿ�, a = ID
			a < 0 ? ant[j].first = p : ant[j].first = L - p; // ID�� �����̸� ���� �̵��� �Ÿ��� p, ID�� ����� ���� �̵��� �Ÿ��� L - p
			ant[j].second = a;
			andId.push_back(a);
		}
		std::sort(ant.begin(), ant.end()); // �̵��� �Ÿ��� ������������ ����
		for (int j = 0; j < N; j++) {
			result[j].first = ant[j].first;
			if (ant[j].second > 0) { result[j].second = andId.back(); andId.pop_back(); } // ������ ��, ID�� ����� �� �� ���Ҹ�
			else { result[j].second = andId.front(); andId.pop_front(); } // ������ ��, ID�� ������ �� ���� ���Ҹ� ����
		}
		std::sort(result.begin(), result.end());
		std::cout << result.at(K - 1).second << std::endl;
	}
	return 0;
}