#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int data;
	Node* leftNode;
	Node* rightNode;

	Node(int data = 0) {
		this->data = data;
		leftNode = nullptr;
		rightNode = nullptr;
	}

	void insertNode(Node*);
	void postTraverse();
};

void Node::insertNode(Node* node) {
	if (this->data < node->data) {
		if (this->rightNode != nullptr)
			this->rightNode->insertNode(node);
		else
			this->rightNode = node;
	}
	else {
		if (this->leftNode != nullptr)
			this->leftNode->insertNode(node);
		else
			this->leftNode = node;
	}
}

void Node::postTraverse() {
	if (this->leftNode != nullptr)
		this->leftNode->postTraverse();
	if (this->rightNode != nullptr)
		this->rightNode->postTraverse();
	cout << data << '\n';
}

int main() {
	int num;
	cin >> num;
	Node* root = new Node(num);

	while (cin >> num) 
		root->insertNode(new Node(num));

	root->postTraverse();
	return 0;
}