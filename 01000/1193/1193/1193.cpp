#include<iostream>
int main() {
	int x;
	std::cin >> x;
	
	// k������ Ȧ¦�� �˾Ƴ��� ���� ����
	int k = 0;

	int i = 1;
	
	while (k < x) {
		k = k + i; i++;
	}
	i--;

	int a = 1, b = 1;

	//Ȧ����
	if (i % 2) {
		b = i;
		b -= k - x;
		a += k - x;
		
	}
	//¦����
	else {
		a = i;
		a -= k - x;
		b += k - x;
		
	}
	std::cout << a << "/" << b;

	return 0;
}