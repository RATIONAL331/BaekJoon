#include<iostream>
#include<string>
class Stack {
private:
	int * arr;
	int rear;
public:
	Stack();
	~Stack();
	int pop();
	void push(int);
	int size();
	bool empty();
	int top();
};
Stack::Stack() {
	arr = new int[10000];
	rear = -1;
}
Stack::~Stack() {
	delete[] arr;
}
void Stack::push(int x) {
	arr[++rear] = x;
}
int Stack::pop() {
	if (rear < 0) {
		return -1;
	}
	return arr[rear--];
}
int Stack::size() {
	return rear + 1;
}
bool Stack::empty() {
	if (rear == -1) return true;
	return false;
}
int Stack::top() {
	if (rear == -1) return -1;
	return arr[rear];
}

int main() {
	int N;
	std::cin >> N;
	std::string direction;
	Stack stack;
	for (int i = 0; i < N; i++) {
		std::cin >> direction;
		if (direction == "push") {
			int X;
			std::cin >> X;
			stack.push(X);
		}
		else if (direction == "pop") {
			std::cout << stack.pop() << std::endl;
		}
		else if (direction == "size") {
			std::cout << stack.size() << std::endl;
		}
		else if (direction == "empty") {
			std::cout << stack.empty() << std::endl;
		}
		else if (direction == "top") {
			std::cout << stack.top() << std::endl;
		}
		else {
			return 0;
		}
	}
	return 0;
}