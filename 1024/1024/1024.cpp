#include<iostream>
void cal(int N, int L) {
	if (L > 100) { std::cout << -1; return; }
	if (L * (L - 1) / 2 > N) { std::cout << -1; return; }

	if (L % 2 == 0) {
		if (N % L == L / 2) {
			int i = 0;
			int j = N / L - L / 2 + 1;
			if (j < 0) { std::cout << -1; return; }
			while (i < L) {
				std::cout << j++ << " ";
				i++;
			}
		}
		else return cal(N, L + 1);
	}
	else {
		if (N % L == 0) { 
			int i = 0;
			int j = N / L - L / 2;
			if (j < 0) { std::cout << -1; return; }
			while (i < L) {
				std::cout << j++ << " ";
				i++;
			}
		}
		else return cal(N, L + 1);
	}
}
int main() {
	int N, L;
	std::cin >> N >> L;

	cal(N, L);
	return 0;
}