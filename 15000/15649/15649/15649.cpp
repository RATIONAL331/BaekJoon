#include<iostream>
#include<vector>
using namespace std;

bool* check;
vector<int> vec;
int N, M;

void execNM(int idx) {
	if (idx == M) {
		for (auto& elem : vec) cout << elem << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i - 1] == false) {
			check[i - 1] = true;
			vec[idx] = i;
			execNM(idx + 1);
			check[i - 1] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	vec.resize(M);
	check = new bool[N]();
	execNM(0);
	delete[] check;
	return 0;
}