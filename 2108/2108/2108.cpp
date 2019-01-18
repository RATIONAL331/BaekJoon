#include<iostream>
int compare(const void* left, const void* right) {
	if (*(int*)left > *(int*)right) return 1;
	else if (*(int*)left < *(int*)right) return -1;
	else return 0;
}
//빈도수를 저장한는 배열을 생성한다.
int* distribution(int* arr, int length) {
	int * tempArr = new int[length];
	//모두 배열 1로 초기화 
	for (int i = 0; i < length; i++) {
		tempArr[i] = 1;
	}
	//첫번째 원소부터
	int i = 0;
	//첫번째 원소 다음 원소를 지정하고 
	//그 숫자가 같다면 다시 다음원소를 지정하여
	//빈도수를 늘린다.
	for (int j = i + 1; j < length; j++) {
		if (arr[i] == arr[j]) {
			tempArr[i]++;
		}
		//다르게 된다면 가르킨 값을 시작으로 다시 시작한다.
		else {
			i = j;
		}
	}
	return tempArr;
}
//최대 빈도값을 계산하는 함수
int calculate(int * arr, int length) {
	int max = 0, maxIndex = -1;
	//최대값과 그것의 인덱스 값을 저장한다.
	for (int i = 0; i < length; i++) {
		if (max < arr[i]) {
			max = arr[i]; maxIndex = i;
		}
	}
	//최대빈도값의 중복도를 확인한다.
	int k = 0;
	for (int i = maxIndex; i < length; i++) {
		if (max == arr[i]) k++;
	}
	//하나도 중복이 되지 않는 다면 바로 인덱스값을 리턴한다.
	if (k <= 1) {
		return maxIndex;
	}
	//중복이 된다면 바로 그 다음 최대 빈도수를 갖는 값의 인덱스를 리턴한다.
	else {
		int temp = maxIndex + 1;
		while (arr[temp] != max) {
			temp++;
		}
		return temp;
	}
	
}
int main() {
	int N;
	std::cin >> N;
	int * arr = new int[N];
	int k, min, max;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> k;
		arr[i] = k;
		sum += k;
	}
	//들어온 배열 정렬하기
	std::qsort(arr, N, sizeof(int), compare);
	//배열을 정렬하였으므로 첫번째 값은 최소값, 마지막 값은 최대값
	min = arr[0]; max = arr[N - 1];
	//빈도수를 새기위한 배열 생성
	int * tempArr = distribution(arr, N);
	//합이 0보다 크면 0.5를 더하고 소수점을 날리고 음수면 0.5를빼고 소수점을 날린다.
	if (sum > 0) {
		sum = int(sum / N + 0.5);
	}
	else {
		sum = int(sum / N - 0.5);
	}
	//산술평군 출력
	std::cout << sum << std::endl;
	//중간값 출력
	std::cout << arr[N / 2] << std::endl;
	//최대빈도값 출력
	std::cout << arr[calculate(tempArr, N)] <<std::endl;
	//길이 출력
	std::cout << max - min << std::endl;
	
	delete[] tempArr;
	delete[] arr;
	return 0;
}