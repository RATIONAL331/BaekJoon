#include<iostream>
int main() {
	int N;
	std::cin >> N;
	if (N == 0) {
		std::cout << 1;
		return 0;
	}
	//들어온 숫자를 한자리씩 저장
	int digit[7];
	//들어온 숫자 갯수 
	int count[10];
	//들어온 숫자 분해하기
	int i = 0;
	while (N > 0) {
		digit[i++] = N % 10;
		N /= 10;
	}

	for (int j = 0; j < 10; j++) count[j] = 0;

	for (int index = 0; index < i; index++) {
		if (digit[index] == 6 || digit[index] == 9) {
			if (count[6] <= count[9]) {
				count[6]++;
			}
			else {
				count[9]++;
			}
		}
		else {
			count[digit[index]]++;
		}
	}
	int max = -1;
	for (int i = 0; i < 10; i++) {
		if (max < count[i]) max = count[i];
	}

	std::cout << max;
	return 0;
}