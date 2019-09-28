#include<iostream>
#include<vector>
using namespace std;

int N, M;

void solve(vector<int>& vec, int idx) {
	if (idx == M) {
		for (auto& elem : vec) cout << elem << " ";
		cout << '\n';
		return;
	}
	for (int elem = vec.back(); elem <= N; elem++) {
		vec.push_back(elem);
		solve(vec, idx + 1);
		vec.pop_back();
	}
}

int main() {
	cin >> N >> M;
	vector<int> vec;
	for (int i = 1; i <= N; i++) {
		vec.push_back(i);
		solve(vec, 1);
		vec.pop_back();
	}
	return 0;
}