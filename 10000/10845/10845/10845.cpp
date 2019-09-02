#include<iostream>
#include<string>
class myQueue {
private :
	int * arr = nullptr;
	int arrSize;
	int arrFront;
	int arrBack;
public:
	myQueue();
	~myQueue();
	void push(int);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
};
myQueue::myQueue() {
	arr = new int[10000];
	arrSize = 0;
	arrFront = 0;
	arrBack = -1;
}
myQueue::~myQueue() {
	if (arr != nullptr) delete[] arr;
}
void myQueue::push(int n) {
	arr[++arrBack] = n;
	arrSize += 1;
}
int myQueue::pop() {
	if (this->empty()) return -1;
	arrSize -= 1;
	return arr[arrFront++];
}
int myQueue::size() {
	return arrSize;
}
bool myQueue::empty() {
	if (arrSize == 0) return true;
	return false;
}
int myQueue::front() {
	if (this->empty()) return -1;
	return arr[arrFront];
}
int myQueue::back() {
	if (this->empty()) return -1;
	return arr[arrBack];
}


int main() {
	int T;
	std::cin >> T;
	std::string line;

	myQueue queue;
	
	for (int i = 0; i < T; i++) {
		std::cin >> line;
		if (line == "push") {
			int num;
			std::cin >> num;
			queue.push(num);
		}
		else if (line == "pop") {
			std::cout << queue.pop() << std::endl;
		}
		else if (line == "size") {
			std::cout << queue.size() << std::endl;
		}
		else if (line == "empty") {
			std::cout << int(queue.empty()) << std::endl;
		}
		else if (line == "front") {
			std::cout << queue.front()<<std::endl;
		}
		else if (line == "back") {
			std::cout << queue.back() << std::endl;
		}
		else {
			return -1;
		}
	}
	return 0;
}