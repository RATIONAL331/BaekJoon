#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
int maxValue = INT32_MIN;

int oper(int before, int after, int op) {
	int ret = 0;
	switch (op) {
	case '+':
		ret = before + after;
		break;
	case '-':
		ret = before - after;
		break;
	case '*':
		ret = before * after;
		break;
	}
	return ret;
}

int calc(vector<int>& ret) {
	int result = ret[0];
	for (int i = 1; i <= N - 2; i += 2)
		result = oper(result, ret[i + 1], ret[i]);

	return result;
}

void solve(vector<int>& ret, int idx) {
	if (idx >= N - 1) {
		maxValue = max(maxValue, calc(ret));
		return;
	}
	int tmpBefore = ret[idx - 1];
	int tmpAfter = ret[idx + 1];
	// 식 바꿔서 다음 수행 실행 (idx + 4)
	ret[idx - 1] = oper(ret[idx - 1], ret[idx + 1], ret[idx]);
	ret[idx] == '*' ? ret[idx + 1] = 1 : ret[idx + 1] = 0;
	solve(ret, idx + 4);
	// 식 원상 복귀 후 다음 수행 실행 (idx + 2)
	ret[idx - 1] = tmpBefore;
	ret[idx + 1] = tmpAfter;
	solve(ret, idx + 2);
}

int main() {
	string str;
	cin >> N >> str;

	if (N == 1) {
		cout << str[0] - '0';
		return 0;
	}

	vector<int> convert(N);
	for (int i = 0; i < N; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			convert[i] = str[i] - '0';
		else
			convert[i] = str[i];
	}

	solve(convert, 1);

	cout << maxValue;

	return 0;
}
