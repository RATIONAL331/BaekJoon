#include<iostream>
#include<vector>
using namespace std;

int N, M;
bool* check;

void solve(vector<int>& vec, int idx) {
	if (idx == M) {
		for (auto& elem : vec) cout << elem << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i - 1] == false) {
			check[i - 1] = true;
			vec[idx] = i;
			solve(vec, idx + 1);
			check[i - 1] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	
	vector<int> vec(M);
	check = new bool[N]();
	solve(vec, 0);

	delete[] check;
	return 0;
}