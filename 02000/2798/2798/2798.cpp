#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> cardVec(N);
	for (int i = 0; i < N; i++)
		cin >> cardVec[i];

	int maxVal = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			for (int k = 0; k < N; k++) {
				if (i == k || j == k) continue;
				int result = cardVec[i] + cardVec[j] + cardVec[k];
				if (result <= M)
					maxVal = max(maxVal, result);
			}
		}
	}

	cout << maxVal;

	return 0;
}

/*
int N, M;
int arr[100];
int maxVal;
void bf(int sum, int idx, int cnt) {
	if (sum > M) return;
	if (cnt == 3) {
		maxVal = max(maxVal, sum);
		return;
	}
	if (idx == N) return;

	bf(sum + arr[idx], idx + 1, cnt + 1);
	bf(sum, idx + 1, cnt);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	bf(0, 0, 0);
	cout << maxVal;
	return 0;
}
*/