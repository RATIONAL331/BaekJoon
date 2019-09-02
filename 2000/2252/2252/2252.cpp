#include<iostream>
#include<vector>
#include<stack>
void dfs(std::vector<int>* vec, int visitNode, bool* visitList, std::stack<int>& stack) {
	// 이미 방문했다면 그냥 나옴
	if (visitList[visitNode]) return;
	visitList[visitNode] = true;
	for (int adjacentNode : vec[visitNode]) {
		// 아직 방문 안했으면
		if (!visitList[adjacentNode]) {
			dfs(vec, adjacentNode, visitList, stack);	
		}
	}
	stack.push(visitNode);
}
int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<int> * personVec = new std::vector<int>[N];
	
	int A, B;
	while (M) {
		std::cin >> A >> B;
		personVec[A - 1].push_back(B - 1);
		M--;
	}
	
	bool* visitCheck = new bool[N];
	std::stack<int> ret;
	for (int i = 0; i < N; i++)
		visitCheck[i] = false;
	
	for (int node = 0; node < N; node++)
		dfs(personVec, node, visitCheck, ret);

	while (!ret.empty()) {
		std::cout << ret.top() + 1 << std::endl;
		ret.pop();
	}

	delete[] visitCheck;
	delete[] personVec;

	return 0;
}