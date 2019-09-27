#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int num;
	int maxVal = 0, minVal = 1000001;
	while (N--) {
		cin >> num;
		maxVal = max(maxVal, num);
		minVal = min(minVal, num);
	}

	cout << minVal * maxVal;

	return 0;
}