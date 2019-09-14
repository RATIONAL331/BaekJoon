#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int sum = 0;
	int idx = N - 1;
	while (K > 0) {
		sum += K / arr[idx];
		K -= (K / arr[idx]) * arr[idx];
		idx--;
	}

	cout << sum;
}