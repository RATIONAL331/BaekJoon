#include<iostream>
int main() {
	int n, k, max = 0, sum = 0;
	std::cin >> n;

	int * score = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> k;
		score[i] = k;
		if (max < k) max = k;
	}

	double ret = 0;
	for (int i = 0; i < n; i++) {
		ret += ((double)score[i] / max) * 100;
	}

	printf("%.2f", ret / n);

	delete[] score;
	return 0;
}