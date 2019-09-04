#include<iostream>
int main() {
	int M;
	std::cin >> M;
	
	int X, Y, current = 1;
	for (int i = 0; i < M; i++) {
		std::cin >> X >> Y;
		if (X == current) current = Y;
		else if (Y == current) current = X;
	}
	std::cout << current;
	return 0;
}