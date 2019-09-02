#include<iostream>
#include<stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	stack<int> st;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) {
			if (!st.empty())
				st.pop();
		}
		else {
			st.push(num);
		}
	}
	int ret = 0;
	while (!st.empty()) {
		ret += st.top();
		st.pop();
	}

	cout << ret;

	return 0;
}