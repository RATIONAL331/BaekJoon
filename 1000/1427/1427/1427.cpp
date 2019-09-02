#include<iostream>
int compare(const void* left, const void* right) {
	if (*(int*)left > *(int*)right)return -1;
	else if (*(int*)left < *(int*)right)return 1;
	else return 0;
}

int main() {
	long long N;
	std::cin >> N;

	long long tempN = N;

	int * arr = nullptr;

	int k = 0;
	while (N > 0) {
		N = N / 10;
		k++;
	}

	arr = new int[k];

	int i = 0;
	while (tempN > 0) {
		arr[i] = tempN % 10;
		tempN /= 10;
		i++;
	}

	std::qsort(arr, k, sizeof(int), compare);

	for (int index = 0; index < k; index++) std::cout << arr[index];

	delete[] arr;

	return 0;
}