#include<iostream>
#include<string>
int main() {
	int second[26];

	std::string word;
	std::getline(std::cin, word);

	for (int i = 0, k = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			second[k++] = i + 3;
		}
	}
	second[15] = 8; second[16] = 8; second[17] = 8; second[18]= 8;
	second[19] = 9; second[20] = 9; second[21] = 9;
	second[22] = 10; second[23] = 10; second[24] = 10; second[25] = 10;

	int ret = 0;

	for (int i = 0; i < word.length(); i++) {
		ret += second[word[i] - 65];
	}

	std::cout << ret;
	return 0;
}