/*#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int main() {
	int N;
	cin >> N;

	vector<int> vec(N);
	vector<int> ret(N);
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec[i] = num;
	}

	stack<int> st;
	for (int i = N - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= vec[i])
			st.pop();

		if (st.empty())
			ret[i] = -1;
		else 
			ret[i] = st.top();

		st.push(vec[i]);
	}

	for (int elem : ret)
		cout << elem << " ";
	return 0;
}
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;



int main() {
	int N;
	cin >> N;

	vector<int> vec(N, -1);
	stack<pair<int, int>> st;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		while (!st.empty() && st.top().first < num) {
			vec[st.top().second] = num;
			st.pop();
		}
		st.push({ num, i });
	}

	for (int elem : vec)
		cout << elem << " ";

	return 0;
}