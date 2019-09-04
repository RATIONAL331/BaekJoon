#include<iostream>
int main() {
	int num, count = 0;
	std::cin >> num;
	int copyNum = num;
	do {
		//num이 일의 자리라면 일의 자릿수*10 + 일의 자릿수
		if((num/10) == 0) {
			num = num * 10 + num;
			count++;
		}
		/*num이 일의 자리가 아니라면
		일의 자릿수*10 + (십의 자릿수 더하기+ 일의 자릿수 더하기)%10*/
		else {
			num = ((num % 10) * 10) + ((num / 10 + num % 10) % 10);
			count++;
		}
	} while (copyNum != num);

	std::cout << count;

	return 0;
}