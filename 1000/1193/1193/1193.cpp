#include<iostream>
int main() {
	int x;
	std::cin >> x;
	
	// kº¯¼ö´Â È¦Â¦À» ¾Ë¾Æ³»±â À§ÇÑ º¯¼ö
	int k = 0;

	int i = 1;
	
	while (k < x) {
		k = k + i; i++;
	}
	i--;

	int a = 1, b = 1;

	//È¦¼ö¸é
	if (i % 2) {
		b = i;
		b -= k - x;
		a += k - x;
		
	}
	//Â¦¼ö¸é
	else {
		a = i;
		a -= k - x;
		b += k - x;
		
	}
	std::cout << a << "/" << b;

	return 0;
}