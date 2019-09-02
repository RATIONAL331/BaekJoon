#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
class Node {
	std::vector<Node> adjcent;
	int data;
	bool visit;
public:
	Node() : Node(0) {}
	Node(int n) {
		this->data = n;
		visit = false;
	}
	int getData() { return data; }
	bool getVisit() { return visit; };
	void addAdjcent(Node n) {
		adjcent.push_back(n);
	}
	std::vector<Node> getAdjcentVector() {
		return adjcent;
	}
	void visitNode() { visit = true; }
	bool operator<(const Node& node) {
		if (this->data < node.data) return true;
		return false;
	}
	void sort() {
		std::sort(adjcent.begin(), adjcent.end());
	}
};

class Graph {
	std::vector<Node> nodeList;
public:
	Graph() : Graph(0) {}
	Graph(int n) {
		for (int i = 0; i < n; i++) {
			nodeList.push_back(Node(i + 1));
		}
	}
	void addEdge(int n1, int n2) {
		nodeList.at(n1 - 1).addAdjcent(nodeList.at(n2 - 1));
		nodeList.at(n2 - 1).addAdjcent(nodeList.at(n1 - 1));
	}
	std::vector<Node> getNodeList() {
		return nodeList;
	}
	void showGraph() {
		for (Node node : nodeList) {
			std::cout << node.getData() << " -> ";
			for (Node adjcent : node.getAdjcentVector()) {
				std::cout << adjcent.getData() << " , ";
			}
			std::cout << std::endl;
		}
	}
	void visit(Node node) {
		visit(node.getData());
	}
	void visit(int n) {
		nodeList.at(n - 1).visitNode();
	}
	bool isVisit(Node node) {
		return isVisit(node.getData());
	}
	bool isVisit(int n) {
		return nodeList.at(n - 1).getVisit();
	}
	void print(Node node) {
		print(node.getData());
	}
	void print(int n) {
		std::cout << n << " ";
	}
	void sort() {
		for (Node node : nodeList) node.sort();
	}
};


void bfs(Graph graph, int V) {
	Node root = graph.getNodeList().at(V - 1);
	std::queue<Node> queue;
	queue.push(root);
	graph.visit(root);
	while (!queue.empty()) {
		Node temp = graph.getNodeList().at(queue.front().getData() - 1);
		queue.pop();
		for (Node node : graph.getNodeList().at(temp.getData() - 1).getAdjcentVector()) {
			if (!graph.isVisit(node)) {
				graph.visit(node);
				queue.push(node);
			}
		}
		graph.print(temp);
	}

}

void dfs(Graph graph, int V) {
	Node root = graph.getNodeList().at(V - 1);
	std::stack<Node> stack;
	stack.push(root);
	graph.visit(root);
	graph.print(root);
	Node temp;
	while (!stack.empty()) {
		bool isTrue = true;
		while(isTrue){
			isTrue = false;
			temp = stack.top();
			for (Node node : graph.getNodeList().at(temp.getData() - 1).getAdjcentVector()) {
				if (!graph.isVisit(node)) {
					graph.visit(node);
					graph.print(node);
					stack.push(node);
					isTrue = true;
					break;
				}
			}
		}
		stack.pop();
	}
}
int main() {
	int N, M, V;
	std::cin >> N >> M >> V;
	
	Graph graph(N);

	int node1, node2;
	for (int i = 0; i < M; i++) {
		std::cin >> node1 >> node2;
		graph.addEdge(node1, node2);
	}

	graph.sort();

	dfs(graph, V);
	std::cout << std::endl;
	bfs(graph, V);
	return 0;
}