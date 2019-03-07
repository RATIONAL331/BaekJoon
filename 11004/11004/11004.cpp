#include<iostream>
#include<vector>
#include<algorithm>
int main() {
	std::ios_base::sync_with_stdio(false);
	int N, K;
	std::cin >> N >> K;
	std::vector<int> vec(N);
	int element;
	for (int i = 0; i < N; i++) {
		std::cin >> element;
		vec[i] = element;
	}
	std::nth_element(vec.begin(), vec.begin() + K - 1, vec.end());
	std::cout << vec[K - 1];
	return 0;
}