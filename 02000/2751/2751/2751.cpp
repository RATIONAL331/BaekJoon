#include<iostream>
int compare(const void* left, const void* right) {
	int tempLeft = *(int*)left;
	int tempRight = *(int*)right;
	if (tempLeft > tempRight) return 1;
	else if (tempLeft < tempRight) return -1;
	else return 0;
}

int main() {
	int N;
	scanf("%d", &N);
	
	int * arr = new int[N];

	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr[i] = num;
	}

	std::qsort(arr, N, sizeof(int), compare);

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

	delete[] arr;

	return 0;
}