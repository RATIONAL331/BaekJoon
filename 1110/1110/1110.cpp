#include<iostream>
int main() {
	int num, count = 0;
	std::cin >> num;
	int copyNum = num;
	do {
		//num�� ���� �ڸ���� ���� �ڸ���*10 + ���� �ڸ���
		if((num/10) == 0) {
			num = num * 10 + num;
			count++;
		}
		/*num�� ���� �ڸ��� �ƴ϶��
		���� �ڸ���*10 + (���� �ڸ��� ���ϱ�+ ���� �ڸ��� ���ϱ�)%10*/
		else {
			num = ((num % 10) * 10) + ((num / 10 + num % 10) % 10);
			count++;
		}
	} while (copyNum != num);

	std::cout << count;

	return 0;
}