#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
class Word {
public:
	std::string word;
public:
	Word() {
		this->word = "-1";
	}
	Word(std::string word){
		this->word = word;
	}
};

bool cmp(const Word& left, const Word& right){
	if (left.word.length() < right.word.length()) return true;
	else if (left.word.length() > right.word.length()) return false;
	else {
		return left.word < right.word;
	}
}

void deleteDuplicate(std::vector<Word>& wordList, int length) {
	for (int index = 0; index < length - 1; index++) {
		if (wordList[index].word == wordList[index + 1].word) {
			wordList[index].word = "-1";
		}
	}
}
int main() {
	int N;
	std::cin >> N;
	std::string word;
	std::vector<Word> wordList;

	for (int i = 0; i < N; i++) {
		std::cin >> word;
		wordList.push_back(Word(word));
	}
	if (N == 1) {
		std::cout << wordList[0].word << std::endl;
	}
	else {
		std::sort(wordList.begin(), wordList.end(), cmp);

		deleteDuplicate(wordList, N);

		for (int i = 0; i < N; i++) {
			if (wordList[i].word != "-1") std::cout << wordList[i].word << std::endl;
		}
	}
	return 0;
}