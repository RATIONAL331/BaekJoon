#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;

int N, M;
vector<int> originalArray;
vector<int> tmpArray;
bitset<9> bit;

void showVector() {
	for (int i : tmpArray)
		cout << i << " ";
	cout << '\n';
}

void solve(int idx) {
	if (tmpArray.size() == M) {
		showVector();
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (bit[i] == true) continue;

		tmpArray.push_back(originalArray[i]);
		bit[i] = true;

		solve(i + 1);

		tmpArray.pop_back();
		bit[i] = false;
	}
}


int main() {
	cin >> N >> M;
	originalArray.resize(N);


	for (int i = 0; i < N; i++)
		cin >> originalArray[i];

	sort(originalArray.begin(), originalArray.end());

	solve(0);

	return 0;
}