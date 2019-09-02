#include<iostream>
int compare(const void* left, const void* right) {
	const int tempL = *(int*)left;
	const int tempR = *(int*)right;
	if (tempL > tempR) return 1;
	else if (tempL < tempR) return -1;
	else return 0;
}

int main(){
	int N;
	std::cin >> N;

	int * arr = new int[N];
	int num;
	for (int i = 0; i < N; i++) {
		std::cin >> num;
		arr[i] = num;
	}

	std::qsort(arr, N, sizeof(int), compare);

	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << std::endl;
	}
	
	delete[] arr;
	return 0;
}