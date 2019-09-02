#include<iostream>
void preOrder(int* inOrder, int* postOrder, int inOrderStartIdx, int inOrderEndIdx, int postOrderStartIdx, int postOrderEndIdx) {
	if (inOrderEndIdx < inOrderStartIdx || postOrderEndIdx < postOrderStartIdx) return;
	int root = postOrder[postOrderEndIdx];
	int rootIdx;
	// inOrder���� root�� ����� ��ġ�� �˾Ƴ�
	for (int i = inOrderStartIdx; i <= inOrderEndIdx; i++) {
		if (inOrder[i] == root) {
			rootIdx = i - inOrderStartIdx;
			break;
		}
	}
	std::cout << root << " ";
	// inOrder�� root�� �������� ���� ������ preOrder�� inOrder�� ���� �κ� ����, ������ �κ� ������ ����(preOrder�� root�� �� �����ʿ� ����)
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