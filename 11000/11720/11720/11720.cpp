#include<iostream>
#include<string>
int main() {
	int n;
	std::cin >> n;

	std::string line;

	int ret = 0;
	
	std::cin.ignore();

	std::getline(std::cin, line);

	for (int i = 0; i < n; i++) {
		ret += int(line[i]) - 48;
	}

	std::cout << ret;

	return 0;
}