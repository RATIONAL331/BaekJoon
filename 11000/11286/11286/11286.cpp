#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

struct myInt {
	int num;
	bool operator<(const myInt& obj) const{
		if (abs(num) < abs(obj.num))
			return false;
		else if (abs(num) == abs(obj.num)) {
			if (num <= obj.num)
				return false;
			else return true;
		}
		else
			return true;
	}
};

int main() {
	int N;
	cin >> N;

	priority_queue<myInt> pq;

	int num;
	while (N--) {
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top().num << '\n';
				pq.pop();
			}
		}
		else {
			pq.push({ num });
		}
	}
	
	return 0;
}