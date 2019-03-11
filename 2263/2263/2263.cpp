#include<iostream>
void preOrder(int* inOrder, int* postOrder, int inOrderStartIdx, int inOrderEndIdx, int postOrderStartIdx, int postOrderEndIdx) {
	if (inOrderEndIdx < inOrderStartIdx || postOrderEndIdx < postOrderStartIdx) return;
	int root = postOrder[postOrderEndIdx];
	int rootIdx;
	// inOrder에서 root의 상대적 위치를 알아냄
	for (int i = inOrderStartIdx; i <= inOrderEndIdx; i++) {
		if (inOrder[i] == root) {
			rootIdx = i - inOrderStartIdx;
			break;
		}
	}
	std::cout << root << " ";
	// inOrder은 root를 기준으로 왼쪽 오른쪽 preOrder은 inOrder의 왼쪽 부분 갯수, 오른쪽 부분 갯수로 구분(preOrder은 root가 맨 오른쪽에 있음)
	preOrder(inOrder, postOrder, inOrderStartIdx, inOrderStartIdx + rootIdx - 1, postOrderStartIdx, postOrderStartIdx + rootIdx - 1);
	preOrder(inOrder, postOrder, inOrderStartIdx + rootIdx + 1, inOrderEndIdx, postOrderStartIdx + rootIdx, postOrderEndIdx - 1);
}
int main() {
	int N;
	std::cin >> N;

	int * inOrder = new int[N];
	int * postOrder = new int[N];
	// inorder input
	int input;
	for (int i = 0; i < N; i++) {
		std::cin >> input;
		inOrder[i] = input;
	}
	// postorder input
	for (int i = 0; i < N; i++) {
		std::cin >> input;
		postOrder[i] = input;
	}
	preOrder(inOrder, postOrder, 0, N - 1, 0, N - 1);
	delete[] inOrder;
	delete[] postOrder;
	return 0;
}