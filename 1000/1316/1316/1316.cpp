#include<iostream>
#include<string>
int n;
bool digit[26];

int calculate(std::string word);

int main() {

	std::cin >> n;
	int ret = 0;
	for (int i = 0; i < 26; i++) {
		digit[i] = false;
	}
	for (int i = 0; i < n; i++) {
		std::string word;
		std::cin >> word;
		ret += calculate(word);
	}

	std::cout << ret;
	return 0;
}
int calculate(std::string word) {
	for (int i = 0; i < 26; i++) {
		digit[i] = false;
	}
	for (int index = 0; index < word.length(); index++) {
		if (!digit[word[index] - 97]) {
			digit[word[index] - 97] = true;
		}
		else {
			if (word[index - 1] == word[index]) {
				continue;
			}
			return 0;
		}
	}
	return 1;
}