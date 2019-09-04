#include<iostream>
#include<vector>

class Node {
public:
	char Data;
	Node* Left;
	Node* Right;
private:
	Node();
public:
	Node(char);

	void addLeft(Node*);
	void addRight(Node*);
	void setData(char);
	void print();
};
Node::Node() : Node('.') {}
Node::Node(char c) {
	this->Left = nullptr;
	this->Right = nullptr;
	this->Data = c;
}

void Node::addLeft(Node* node) {
	this->Left = node;
}
void Node::addRight(Node* node) {
	this->Right = node;
}
void Node::setData(char c) {
	this->Data = c;
}
void Node::print() {
	std::cout << this->Data;
}

void printPreorder(Node* startNode) {
	if (startNode == nullptr) {
		return;
	}
	startNode->print();
	printPreorder(startNode->Left);
	printPreorder(startNode->Right);
}

void printInorder(Node* startNode) {
	if (startNode == nullptr) {
		return;
	}
	printInorder(startNode->Left);
	startNode->print();
	printInorder(startNode->Right);
}

void printPostorder(Node* startNode) {
	if (startNode == nullptr) {
		return;
	}
	printPostorder(startNode->Left);
	printPostorder(startNode->Right);
	startNode->print();
}


int main() {
	int N;
	std::cin >> N;

	char alpha = 65;
	
	std::vector<Node*> nodeArr;

	for (int i = 0; i < N; i++) {
		nodeArr.push_back(new Node(alpha++));
	}

	char temp;
	for (int i = 0; i < N; i++) {
		std::cin >> temp;
		std::cin >> alpha;
		if (alpha != '.') {
			nodeArr[temp - 'A']->addLeft(nodeArr[alpha - 'A']);
		}
		std::cin >> alpha;
		if (alpha != '.') {
			nodeArr[temp - 'A']->addRight(nodeArr[alpha - 'A']);
		}
	}

	printPreorder(nodeArr[0]);
	std::cout << '\n';
	printInorder(nodeArr[0]);
	std::cout << '\n';
	printPostorder(nodeArr[0]);

	for (int i = 0; i < N; i++) {
		delete nodeArr[i];
	}

	return 0;
}