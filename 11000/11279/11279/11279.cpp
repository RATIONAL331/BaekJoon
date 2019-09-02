#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	priority_queue<int> pq;

	int num;
	while (N--) {
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else 
			pq.push(num);
	}
	return 0;
}