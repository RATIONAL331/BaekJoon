#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	priority_queue<int> pq_max;
	priority_queue<int> pq_min;

	int elem;
	for (int i = 0; i < N; i++) {
		cin >> elem;
		if (pq_max.size() == pq_min.size())
			pq_max.push(elem);
		else 
			pq_min.push(-elem);

		if (!pq_min.empty() && !pq_max.empty() && -pq_min.top() < pq_max.top()) {
			int a = pq_max.top(); pq_max.pop();
			int b = -pq_min.top(); pq_min.pop();
			pq_max.push(b); pq_min.push(-a);
		}
		printf("%d\n", pq_max.top());
	}
	
	return 0;
}