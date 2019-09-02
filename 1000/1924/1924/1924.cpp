#include<iostream>
int main() {
	int x, y;
	std::cin >> x >> y;
	int count = 1;

	const char* arr[] = { "SUN","MON" ,"TUE","WED","THU","FRI","SAT" };
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	for (int i = 1; i < x; i++) 
		count += days[i-1];
	count += y; count %= 7;
	std::cout << arr[(count+6)%7];
	return 0;
}