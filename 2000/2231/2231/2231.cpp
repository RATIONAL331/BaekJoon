#include<iostream>
using namespace std;
int partitialSum(int num) {
	int sum = num;
	while (num) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int main() {
	int N;
	cin >> N;

	int i;
	for (i = 0; i < N; i++) {
		if (partitialSum(i) == N) break;
	}
	if (i == N)
		printf("0");
	else
		printf("%d", i);

	return 0;
}