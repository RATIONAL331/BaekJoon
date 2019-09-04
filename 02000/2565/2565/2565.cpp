#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1000];
int getLIS(vector<pair<int, int>>& vec, size_t pos) {
	int& ret = dp[pos];
	if (ret != 0) return ret;

	ret = 1;
	for (size_t next = pos + 1; next < vec.size(); next++) {
		if (vec[pos].second < vec[next].second)
			ret = max(ret, getLIS(vec, next) + 1);
	}
	return ret;
}

int main() {
	int N;
	cin >> N;
	
	vector<pair<int, int>> vec(N);
	int A, B;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		vec[i] = { A, B };
	}
	sort(vec.begin(), vec.end());

	int lis = -1;
	for (int begin = 0; begin < N; begin++)
		lis = max(lis, getLIS(vec, begin));
	
	cout << N - lis;

	return 0;
}