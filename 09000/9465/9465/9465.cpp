#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	int n;
	while (T--) {
		vector<vector<int>> vec(2);
		cin >> n;

		vec[0].resize(n);
		vec[1].resize(n);

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> vec[i][j];

		vec[0][1] += vec[1][0];
		vec[1][1] += vec[0][0];

		for (int i = 2; i < n; i++) {
			vec[0][i] += max(vec[1][i - 1], vec[1][i - 2]);
			vec[1][i] += max(vec[0][i - 1], vec[0][i - 2]);
		}

		cout << max(vec[0][n - 1], vec[1][n - 1]) << '\n';
	}
	return 0;
}