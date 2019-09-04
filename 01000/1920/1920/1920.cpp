#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> A;

	int X;
	for (int i = 0; i < N; i++) {
		cin >> X;
		A.push_back(X);
	}
	sort(A.begin(), A.end());

	int M;
	cin >> M;

	int num;
	while (M--) {
		cin >> num;
		cout << binary_search(A.begin(), A.end(), num) << '\n';
	}

	return 0;
}