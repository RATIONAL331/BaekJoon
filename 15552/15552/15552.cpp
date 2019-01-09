#include<iostream>
int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T-1; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d", a + b);
	return 0;
}