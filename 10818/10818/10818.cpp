#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int min = 987654321;
	int max = -987654321;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (max < num)
			max = num;
		if (min > num)
			min = num;
	}

	cout << min << " " << max;

	return 0;
}