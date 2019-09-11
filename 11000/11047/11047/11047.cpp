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
	int total = 0;
	int idx = N - 1;
	while (total < K) {
		total += (K / arr[idx]) * arr[idx];
		sum += K / arr[idx];
		K = K - (K / arr[idx]) * arr[idx];
		idx--;
	}

	cout << sum;
}