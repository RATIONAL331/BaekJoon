#include<iostream>
int main() {
	int c, n, k;
	double sum;
	std::cin >> c;


	for (int i = 0; i < c; i++) {
		std::cin >> n;
		sum = 0;
		int * score = new int[n];
		for (int j = 0; j < n; j++) {
			std::cin >> k;
			score[j] = k;
			sum += k;
		}

		double avg = sum / n;

		int count = 0;
		for (int j = 0; j < n; j++) {
			if (avg < score[j]) count++;
		}
		printf("%.3f%%\n", ((double)count / n) * 100);

		delete[] score;
	}
	return 0;
}