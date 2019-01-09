#include<iostream>
int main() {
	int n, x, compare;
	scanf_s("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &compare);
		if (compare < x) std::cout << compare << " ";
	}
	return 0;
}