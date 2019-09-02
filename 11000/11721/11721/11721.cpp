#include<iostream>
#include<string>
int main() {
	std::string line;
	std::getline(std::cin, line);

	int length = line.length();
	int end = 0;
	while (end < length) {
		for (int i = 0; i < 10; i++) {
			if(end<length)
				std::cout << line[end++];
		}
		std::cout << std::endl;
	}
	return 0;
}