#include<iostream>
#include<algorithm>
int main() {
	int in, out, max = 0, pNum = 0;
	for (int i = 0; i < 4; i++) {
		std::cin >> out >> in;
		pNum = pNum + in - out;
		max = std::max(max, pNum);
	}
	std::cout << max;
	return 0;
}