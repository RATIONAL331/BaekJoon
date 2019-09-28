#include<iostream>
#include<vector>
using namespace std;

int N, M;
void solve(vector<int>& vec, int cur, int idx) {
	if (idx == M) {
		for (auto& elem : vec) cout << elem << " ";
		cout << '\n';
		return;
	}
	for (int elem = cur; elem < N; elem++) {
		vec.push_back(elem + 1);
		solve(vec, cur, idx + 1);
		vec.pop_back();
	}

}

int main() {
	cin >> N >> M;
	vector<int> vec;

	solve(vec, 0, 0);
	return 0;
}