#include<iostream>
#include<vector>
#include<algorithm>
int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec(N);
	int num;
	for (int i = 0; i < N; i++) {
		std::cin >> num;
		vec.at(i).first = num;
		vec.at(i).second = i;
	}
	std::sort(vec.begin(), vec.end());

	int i = 0;
	std::vector<std::pair<int, int>> ret;
	for (std::pair<int, int> elem : vec) {
		std::pair<int, int> tmp;
		tmp.first = elem.second;
		tmp.second = i++;
		ret.push_back(tmp);
	}
	std::sort(ret.begin(), ret.end());

	for (std::pair<int, int> elem : ret) {
		std::cout << elem.second << " ";
	}

	return 0;
}