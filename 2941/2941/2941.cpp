#include<iostream>
#include<string>
int main() {
	std::string word;
	std::getline(std::cin, word);

	int count = 0;
	int i = 0;
	while (i < word.length()) {
		if (word[i] == 'c') {
			if (i + 1 < word.length() && (word[i + 1] == '=' || word[i + 1] == '-')) {
				count++;
				i += 2;
			}
			else {
				count++;
				i += 1;
			}
		}
		else if (word[i] == 'd') {
			if (i + 1 < word.length() && word[i + 1] == '-') {
				count++;
				i += 2;
			}
			else if (i + 2 < word.length() && word[i + 1] == 'z' && word[i + 2] == '=') {
				count++;
				i += 3;
			}
			else {
				count++;
				i += 1;
			}
		}
		else if (word[i] == 'l') {
			if (i + 1 < word.length() && word[i + 1] == 'j') {
				count++;
				i += 2;
			}
			else {
				count++;
				i += 1;
			}
		}
		else if (word[i] == 'n') {
			if (i + 1 < word.length() && word[i + 1] == 'j') {
				count++;
				i += 2;
			}
			else {
				count++;
				i += 1;
			}
		}
		else if (word[i] == 's') {
			if (i + 1 < word.length() && word[i + 1] == '=') {
				count++;
				i += 2;
			}
			else {
				count++;
				i += 1;
			}
		}
		else if (word[i] == 'z') {
			if (i + 1 < word.length() && word[i + 1] == '=') {
				count++;
				i += 2;
			}
			else {
				count++;
				i += 1;
			}
		}
		else {
			count++;
			i += 1;
		}
	}

	std::cout << count;

	return 0;
}