#include<iostream>
int compare(const void* left, const void* right) {
	if (*(int*)left > *(int*)right) return 1;
	else if (*(int*)left < *(int*)right) return -1;
	else return 0;
}
//�󵵼��� �����Ѵ� �迭�� �����Ѵ�.
int* distribution(int* arr, int length) {
	int * tempArr = new int[length];
	//��� �迭 1�� �ʱ�ȭ 
	for (int i = 0; i < length; i++) {
		tempArr[i] = 1;
	}
	//ù��° ���Һ���
	int i = 0;
	//ù��° ���� ���� ���Ҹ� �����ϰ� 
	//�� ���ڰ� ���ٸ� �ٽ� �������Ҹ� �����Ͽ�
	//�󵵼��� �ø���.
	for (int j = i + 1; j < length; j++) {
		if (arr[i] == arr[j]) {
			tempArr[i]++;
		}
		//�ٸ��� �ȴٸ� ����Ų ���� �������� �ٽ� �����Ѵ�.
		else {
			i = j;
		}
	}
	return tempArr;
}
//�ִ� �󵵰��� ����ϴ� �Լ�
int calculate(int * arr, int length) {
	int max = 0, maxIndex = -1;
	//�ִ밪�� �װ��� �ε��� ���� �����Ѵ�.
	for (int i = 0; i < length; i++) {
		if (max < arr[i]) {
			max = arr[i]; maxIndex = i;
		}
	}
	//�ִ�󵵰��� �ߺ����� Ȯ���Ѵ�.
	int k = 0;
	for (int i = maxIndex; i < length; i++) {
		if (max == arr[i]) k++;
	}
	//�ϳ��� �ߺ��� ���� �ʴ� �ٸ� �ٷ� �ε������� �����Ѵ�.
	if (k <= 1) {
		return maxIndex;
	}
	//�ߺ��� �ȴٸ� �ٷ� �� ���� �ִ� �󵵼��� ���� ���� �ε����� �����Ѵ�.
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
	//���� �迭 �����ϱ�
	std::qsort(arr, N, sizeof(int), compare);
	//�迭�� �����Ͽ����Ƿ� ù��° ���� �ּҰ�, ������ ���� �ִ밪
	min = arr[0]; max = arr[N - 1];
	//�󵵼��� �������� �迭 ����
	int * tempArr = distribution(arr, N);
	//���� 0���� ũ�� 0.5�� ���ϰ� �Ҽ����� ������ ������ 0.5������ �Ҽ����� ������.
	if (sum > 0) {
		sum = int(sum / N + 0.5);
	}
	else {
		sum = int(sum / N - 0.5);
	}
	//����� ���
	std::cout << sum << std::endl;
	//�߰��� ���
	std::cout << arr[N / 2] << std::endl;
	//�ִ�󵵰� ���
	std::cout << arr[calculate(tempArr, N)] <<std::endl;
	//���� ���
	std::cout << max - min << std::endl;
	
	delete[] tempArr;
	delete[] arr;
	return 0;
}