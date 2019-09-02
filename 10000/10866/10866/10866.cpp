#include<iostream>
#include<string>
#include<deque>
int main() {
	int N;
	std::cin >> N;

	std::deque<int> deque;
	std::string line;
	for (int i = 0; i < N; i++) {
		std::cin >> line;
		
		int number;
		if (line == "push_front") {
			std::cin >> number;
			deque.push_front(number);
		}
		else if (line == "push_back") {
			std::cin >> number;
			deque.push_back(number);
		}
		else if (line == "pop_front") {
			if (deque.empty()) std::cout << "-1" << std::endl;
			else {
				std::cout << deque.front() << std::endl;
				deque.pop_front();
			}
		}
		else if (line == "pop_back") {
			if (deque.empty()) std::cout << "-1" << std::endl;
			else {
				std::cout << deque.back() << std::endl;
				deque.pop_back();
			}
		}
		else if (line == "size") {
			std::cout << deque.size() << std::endl;
		}
		else if (line == "empty") {
			if(deque.empty()) std::cout << 1 << std::endl;
			else { std::cout << 0 << std::endl; }
		}
		else if (line == "front") {
			if (deque.empty()) std::cout << "-1" << std::endl;
			else { std::cout << deque.front() << std::endl; }
		}
		else if (line == "back") {
			if (deque.empty()) std::cout << "-1" << std::endl;
			else { std::cout << deque.back() << std::endl; }
		}
	}
	return 0;
}