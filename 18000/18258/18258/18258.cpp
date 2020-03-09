#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	
	queue<int> que;

	string order;
	while (N--) {
		cin >> order;

		if (order == "push") {	
			int number;
			cin >> number;
			que.push(number);
		}
		else if (order == "pop") {
			if (que.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << que.front() << '\n';
			que.pop();
		}
		else if (order == "size")
			cout << que.size() << '\n';
		else if (order == "empty")
			cout << que.empty() << '\n';
		else if (order == "front") {
			if (que.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << que.front() << '\n';
		}
		else {
			if (que.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << que.back() << '\n';
		}
	}
	return 0;
}