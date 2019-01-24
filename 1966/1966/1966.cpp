#include<iostream>
#include<queue>
class PriorityPage {
public:
	int pageNum;
	int priority;
	PriorityPage(int pageNum, int priority) {
		this->pageNum = pageNum;
		this->priority = priority;
	}
	PriorityPage() {
		this->pageNum = -1;
		this->priority = 0;
	}
};

class PriorityPageQueue {
private:
	PriorityPage ** priorityQueue;
	int size;
	int front;
	int back;
public:
	PriorityPageQueue() {
		priorityQueue = new PriorityPage*[10000];
		size = 0;
		front = 0;
		back = -1;
	}
	~PriorityPageQueue() {
		if (priorityQueue != nullptr) {
			for (int i = front; i <= back; i++) { delete priorityQueue[i]; }
			delete[] priorityQueue;
		}
	}
	void push(PriorityPage* page) {
		priorityQueue[++back] = page;
		size += 1;
	}
	void pop() {
		if (this->isEmpty()) return;
		size -= 1;
		delete priorityQueue[front++];
	}
	PriorityPage* getBack() {
		if (this->isEmpty()) return NULL;
		return priorityQueue[back];
	}
	PriorityPage* getFront() {
		if (this->isEmpty()) return NULL;
		return priorityQueue[front];
	}
	int getMaxPriority() {
		if (this->isEmpty()) return -1;
		int temp = priorityQueue[front]->priority;
		for (int i = front; i <= back; i++) {
			if (temp < priorityQueue[i]->priority) {
				temp = priorityQueue[i]->priority;
			}
		}
		return temp;
	}
	int getSize() {
		return size;
	}
	bool isEmpty() {
		if (size == 0) return true;
		return false;
	}
};

int main() {
	int T;
	std::cin >> T;

	int N, M;
	for (int i = 0; i < T; i++) {
		std::cin >> N >> M;
		
		PriorityPageQueue* Queue = new PriorityPageQueue();
		int priority;
		for (int i = 0; i < N; i++) {
			std::cin >> priority;
			Queue->push(new PriorityPage(i, priority));
		}
		
		int ret = 1;
		while (!Queue->isEmpty()) {
			if (Queue->getFront()->pageNum == M && Queue->getFront()->priority == Queue->getMaxPriority()) { break; }
			else if (Queue->getFront()->priority == Queue->getMaxPriority()) { Queue->pop(); ret++; }
			else {
				PriorityPage* temp = new PriorityPage(Queue->getFront()->pageNum, Queue->getFront()->priority);
				Queue->pop();
				Queue->push(temp);
			}
		}
		std::cout << ret << std::endl;
		delete Queue;
	}
	return 0;
}