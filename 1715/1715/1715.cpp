#include<iostream>
class Heap {
private:
	int size;
	int * heapArr;
public:
	Heap() {
		this->size = 0;
		heapArr = nullptr;
	}
	Heap(int n) {
		this->size = 0;
		heapArr = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			heapArr[i] = INT32_MAX;
		}
	}
	~Heap() {
		if (heapArr != nullptr) delete[] heapArr;
	}
	Heap(const Heap& heap) {
		this->size = heap.size;
		if (heap.heapArr == nullptr) { this->heapArr = nullptr; }
		else { this->heapArr = new int[heap.size + 1]; }
		for (int i = 0; i < this->size + 1; i++) {
			this->heapArr[i] = heap.heapArr[i];
		}
	}
	Heap& operator=(const Heap& heap) {
		this->size = heap.size;
		if (this->heapArr != nullptr) {
			delete[] this->heapArr;
			this->heapArr = new int[heap.size + 1];
			for (int i = 0; i < this->size + 1; i++) {
				this->heapArr[i] = heap.heapArr[i];
			}
		}
	}
	void insert(int n) {
		int idx = ++(this->size);
		this->heapArr[idx] = n;
		if (idx != 1) heapify(idx, 0);
	}
	int pop() {
		int ret = this->heapArr[1];
		this->heapArr[1] = this->heapArr[this->size];
		heapArr[(this->size)--] = INT32_MAX;
		heapify(1, 1);
		return ret;
	}
	void heapify(int idx, int k) {
		if (idx > size) return;
		// 삭제과정 k = 1 
		if (k == 1) {
			// 자식이 오른쪽 왼쪽 둘다 존재하는 경우
			if (this->size >= idx * 2 + 1 && (this->heapArr[idx * 2 + 1] < this->heapArr[idx] || this->heapArr[idx * 2] < this->heapArr[idx])) {
				if (this->heapArr[idx * 2 + 1] < this->heapArr[idx * 2]) {
					std::swap(this->heapArr[idx * 2 + 1], this->heapArr[idx]);
					heapify(idx * 2 + 1, 1);
				}
				else {
					std::swap(this->heapArr[idx * 2], this->heapArr[idx]);
					heapify(idx * 2, 1);
				}

			}
			// 자식이 왼쪽만 존재하는 경우
			else if (this->size >= idx * 2 && this->heapArr[idx * 2] < this->heapArr[idx]) {
				std::swap(this->heapArr[idx * 2], this->heapArr[idx]);
				heapify(idx * 2, 1);
			}
		}
		// 그 외에는 모두 삽입 과정
		else {
			if (this->heapArr[idx / 2] > this->heapArr[idx]) {
				std::swap(this->heapArr[idx / 2], this->heapArr[idx]);
				if (idx / 2 != 1) heapify(idx / 2, 0);
			}

		}
	}
	bool empty() {
		return this->size == 0;
	}
	int getSize() {
		return this->size;
	}
};
int main() {
	int N;
	std::cin >> N;

	Heap heap(N);
	int deckCount;
	for (int i = 0; i < N; i++) {
		std::cin >> deckCount;
		heap.insert(deckCount);
	}
	int sum = 0;
	while (heap.getSize() != 1) {
		int n1 = heap.pop();
		int n2 = heap.pop();
		heap.insert(n1 + n2);
		sum += n1 + n2;
	}
	printf("%d", sum);
	return 0;
}