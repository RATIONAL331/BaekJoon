#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	int ret = 0;

	vector<int> sum(N);
	sum[0] = vec[0];
	ret += sum[0];
	for (int i = 1; i < N; i++) {
		sum[i] = vec[i] + sum[i - 1];
		ret += sum[i];
	}

	cout << ret;

	return 0;
}