#include<iostream>
#include<deque>
int getPos(std::deque<int>& Deque, int findNumber) {
	int pos = 0;
	for (int num : Deque) {
		if (num == findNumber) return pos;
		pos++;
	}
}
int main() {
	int N, M;
	std::cin >> N >> M;

	std::deque<int> Deque;

	for (int i = 0; i < N; i++) {
		Deque.push_back(i + 1);
	}
	int pos;
	int ret = 0;

	for (int i = 0; i < M; i++) {
		std::cin >> pos;
		int temp = getPos(Deque, pos);
	
		if (Deque.front() == Deque[temp]) {
			Deque.pop_front();
		}
		else {
			if ((Deque.size() - 1) - temp < (Deque.size() - 1) / 2) { // 찾는 값이 오른쪽에 치우쳐 있다면
				for (int i = 0; i < Deque.size() - temp; i++) {
					Deque.push_front(Deque.back());
					Deque.pop_back();
					ret++;
				}
				Deque.pop_front();
			}
			else { // 찾는 값이 왼쪽에 치우쳐 있다면
				for (int i = 0; i < temp; i++) {
					Deque.push_back(Deque.front());
					Deque.pop_front();
					ret++;
				}
				Deque.pop_front();
			}
		}
	}
	std::cout << ret;
	return 0;
}