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

// A의 부모를 B로 바꾼다.
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
		// 각 원들의 부모들을 초기화 시킨다. 각각 자기 자신을 가르키도록 한다.
		for (int parentInit = 0; parentInit < N; parentInit++) {
			parentArr[parentInit] = parentInit;
		}
		// 원을 하나씩 입력받는다.
		for (int circleInput = 0; circleInput < N; circleInput++) {
			int x, y, R;
			cin >> x >> y >> R;
			circleArr[circleInput] = Circle(x, y, R);

			// 원들 간의 관계를 저장해 둔다.
			for (int adjacenting = 0; adjacenting < circleInput; adjacenting++) {
				// 새로 들어온 원을 기존에 입력된 원들과 비교해가면서
				// 기존의 원과 겹치는 부분이 있다면 서로 연결한다.
				if (circleArr[circleInput].isInside(circleArr[adjacenting])) {
					circleArr[circleInput].adjacent.push_back(adjacenting);
					circleArr[adjacenting].adjacent.push_back(circleInput);
				}
			}
		}
		bool* visitArr = new bool[N];
		for (int visitInit = 0; visitInit < N; visitInit++)
			visitArr[visitInit] = false;
		// 원의 관계 파악하면서 0번째 원부터 차례대로 연결되어 있는 원들을 방문하면서 그들을 자신의 부모로 바꾼다.
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