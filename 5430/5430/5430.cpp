#include<iostream>
#include<string>
#include<deque>
void functionR(std::deque<int>& deque){
	for (int i = 0; i < deque.size() / 2; i++) {
		std::swap(deque.at(i), deque.at(deque.size() - 1 - i));
	}
}
bool functionD(std::deque<int>& deque) {
	if (deque.empty()) return false;
	deque.pop_front();
	return true;
}
void printDeque(const std::deque<int>& deque) {
	std::cout << "[";
	for (int i = 0; i < deque.size() - 1; i++) {
		std::cout << deque.at(i) << ",";
	}
	std::cout << deque.at(deque.size() - 1) << "]" << std::endl;
}
int main() {
	int T;
	std::cin >> T;

	std::deque<int> deque;

	std::string p;
	int n;
	std::string array;
	for (int i = 0; i < T; i++) {
		std::cin >> p;
		std::cin >> n;
		std::cin >> array;
		
		// do tokenizer

		bool success = true;
		for (char function : p) {
			if (function == 'R') {
				functionR(deque);
			}
			else { // function == 'D'
				if (!functionD(deque)) success = false;
			}
		}
		if (!success) {
			std::cout << "error" << std::endl;
		}
		else { 
			printDeque(deque);
		}
	}
	return 0;
}