#include<iostream>
#include<string>
int main() {
	int n;
	std::cin >> n;

	std::string line;

	int current, sum;

	for (int i = 0; i < n; i++) {
		std::cin >> line;

		sum = 0;
		current = 0;

		for (int index = 0; index < line.length(); index++) {
			if (line[index] == 'X') {
				current = 0;
			}
			else {
				current++;
				sum += current;
			}
		}

		std::cout << sum << std::endl;
	}
	
	return 0;
}