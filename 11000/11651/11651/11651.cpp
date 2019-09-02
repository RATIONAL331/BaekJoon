#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> vec;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		vec.push_back({ y, x });
	}

	sort(vec.begin(), vec.end());

	for (pair<int, int>& elem : vec)
		cout << elem.second << " " << elem.first << '\n';

	return 0;
}