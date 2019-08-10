#include<iostream>
#include<cmath>
using namespace std;

const int allSum = 1 + 2 + 3;
void hanoi(int K, int from, int to) {
	if (K == 0)
		return;
	hanoi(K - 1, from, allSum - (from + to));
	printf("%d %d\n", from, to);
	hanoi(K - 1, allSum - (from + to), to);
}

int main() {
	int N;
	cin >> N;
	printf("%d\n", (int)pow(2, N) - 1);

	hanoi(N, 1, 3);

	return 0;
}