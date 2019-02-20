#include<iostream>
int main() {
	while (true) {
		int ret = 0;
	
		int n;
		for (int i = 0; i < 4; i++) {
			std::cin >> n;
			if (std::cin.eof())return 0;
			ret += n;
		}
		switch (ret) {
		case 0:
			std::cout << 'D' << std::endl;
			break;
		case 1:
			std::cout << 'C' << std::endl;
			break;
		case 2:
			std::cout << 'B' << std::endl;
			break;
		case 3:
			std::cout << 'A' << std::endl;
			break;
		case 4:
			std::cout << 'E' << std::endl;
			break;
		}
	}
	return 0;
}