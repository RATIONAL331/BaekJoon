#include<iostream>
int main() {
	int n;
	std::cin >> n;
	int numArr[10001] = { 0, };
	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		numArr[num]++;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < numArr[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}