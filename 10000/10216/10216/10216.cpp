#include<iostream>
#include<vector>
using namespace std;
class Circle {
public:
	int posX;
	int posY;
	int radius;

	vector<int> adjacent;

	Circle(int x = 0, int y = 0, int R = 0)
	:posX(x), posY(y), radius(R)
	{
	/*empty construction*/
	}
	bool isInside(const Circle& c) {
		return (posX - c.posX) * (posX - c.posX) + (posY - c.posY) * (posY - c.posY) <= (radius + c.radius) * (radius + c.radius);
	}
};

int find(int* arr, int nodeA) {
	if (arr[nodeA] == nodeA) return nodeA;
	return arr[nodeA] = find(arr, arr[nodeA]);
}

// A�� �θ� B�� �ٲ۴�.
void parenting(int* arr, int nodeA, int nodeB) {
	int parentA = find(arr, nodeA);
	int parentB = find(arr, nodeB);

	arr[parentA] = parentB;
}

void dfs(Circle* circleArr, int* parentArr, bool* visitArr, int node, int parent) {
	if (visitArr[node]) return;

	visitArr[node] = true;
	parenting(parentArr, node, parent);
	for (int adj : circleArr[node].adjacent) {
		dfs(circleArr, parentArr, visitArr, adj, parent);
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		Circle* circleArr = new Circle[N];
		int* parentArr = new int[N];
		// �� ������ �θ���� �ʱ�ȭ ��Ų��. ���� �ڱ� �ڽ��� ����Ű���� �Ѵ�.
		for (int parentInit = 0; parentInit < N; parentInit++) {
			parentArr[parentInit] = parentInit;
		}
		// ���� �ϳ��� �Է¹޴´�.
		for (int circleInput = 0; circleInput < N; circleInput++) {
			int x, y, R;
			cin >> x >> y >> R;
			circleArr[circleInput] = Circle(x, y, R);

			// ���� ���� ���踦 ������ �д�.
			for (int adjacenting = 0; adjacenting < circleInput; adjacenting++) {
				// ���� ���� ���� ������ �Էµ� ����� ���ذ��鼭
				// ������ ���� ��ġ�� �κ��� �ִٸ� ���� �����Ѵ�.
				if (circleArr[circleInput].isInside(circleArr[adjacenting])) {
					circleArr[circleInput].adjacent.push_back(adjacenting);
					circleArr[adjacenting].adjacent.push_back(circleInput);
				}
			}
		}
		bool* visitArr = new bool[N];
		for (int visitInit = 0; visitInit < N; visitInit++)
			visitArr[visitInit] = false;
		// ���� ���� �ľ��ϸ鼭 0��° ������ ���ʴ�� ����Ǿ� �ִ� ������ �湮�ϸ鼭 �׵��� �ڽ��� �θ�� �ٲ۴�.
		for (int parentingIdx = 0; parentingIdx < N; parentingIdx++) {
			dfs(circleArr, parentArr, visitArr, parentingIdx, parentingIdx);
		}

		bool* retArr = new bool[N];
		for (int retInit = 0; retInit < N; retInit++)
			retArr[retInit] = false;
		
		int ans = 0;
		for (int reting = 0; reting < N; reting++) {
			if (retArr[parentArr[reting]] == false) {
				retArr[parentArr[reting]] = true;
				ans++;
			}
		}

		printf("%d\n", ans);

		delete[] retArr;
		delete[] visitArr;
		delete[] parentArr;
		delete[] circleArr;
	}
	return 0;
}