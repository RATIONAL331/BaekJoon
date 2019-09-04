#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N;
	cin >> N;

	priority_queue<int> pq;

	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;

			if (pq.size() == N) {
				if (-pq.top() <= num) {
					pq.pop();
					pq.push(-num);
				}
			}
			else 
				pq.push(-num);
		}
	}
	printf("%d\n", -pq.top());

	return 0;
}