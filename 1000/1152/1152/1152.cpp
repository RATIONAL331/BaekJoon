#include<iostream>
#include<string>
int main() {
	std::string line;
	std::getline(std::cin, line);
	int count = 0;
	for (int i = 1; i < line.length() - 1; i++) {
		if (line[i - 1] != ' ' && line[i] == ' ' && line[i + 1] != ' ')
			count++;
	}
	if (line.length() <= 1) {
		if (line == "" || line == " ") {
			std::cout << 0;
		}
		else {
			std::cout << count + 1;
		}
	}
	else {
		std::cout << count + 1;
	}
	
	return 0;
}