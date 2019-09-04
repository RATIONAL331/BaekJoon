#include<iostream>
#include<vector>
#include<algorithm>
int main() {
	int height;
	std::vector<int> arr(9);
	
	int sum = 0;

	for(int i=0; i<9; i++){
		std::cin >> height;
		sum += height;
		arr[i] = height;
	}
	
	bool isBreak = true;
	int i, j;
	for (i = 0; i < 9 && isBreak; i++) {
		for (j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				isBreak = false;
				break;
			}	
		}
	}
	
	arr[i - 1] = 0; arr[j] = 0;

	std::sort(arr.begin(), arr.end());
	

	for (int i = 0; i < 9; i++) {
		if (arr[i] != 0)
			std::cout << arr[i] << std::endl;
	}

	return 0;
}