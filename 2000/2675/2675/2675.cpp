#include<iostream>
#include<string>
int main() {
	int T;
	std::cin >> T;
	for(int i=0; i<T; i++) {
		int n;
		std::string word;
		std::cin >> n;
		std::cin >> word;
		for (int k = 0; k < word.length(); k++) {
			for (int j = 0; j < n; j++) {
				std::cout << word[k];
			}
		}
		std::cout << std::endl;
	}
	return 0;
}