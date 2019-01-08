#include<iostream>
#include<string>
int main() {
	char line[101];
	while(true) {
		std::cin.getline(line, 101);
		if (std::cin.eof()) return 0;
		std::cout << line << std::endl;	
	}
	return 0;
}