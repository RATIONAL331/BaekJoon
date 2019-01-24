#include<iostream>
#include<queue>
int main() {
	int N, M;
	std::cin >> N >> M;

	std::queue<int> josepus;
	std::vector<int> ret;
	for (int i = 1; i <= N; i++)  josepus.push(i);

	int kill = 0;
	while (!josepus.empty()) {
		if (++kill % M == 0) {
			ret.push_back(josepus.front());
			josepus.pop();
		}
		else {
			josepus.push(josepus.front());
			josepus.pop();
		}
	}

	std::cout << "<";
	for (int i = 0; i < ret.size() - 1; i++) {
		std::cout << ret[i] << ", ";
	}
	std::cout << ret[ret.size() - 1] << ">";

	return 0;
}