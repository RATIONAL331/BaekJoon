#include<iostream>
#include<cmath>
using namespace std;
class Circle {
public:
	int posX;
	int posY;
	int radius;
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

void dfs(int* parentArr, bool* visitArr, int node, int parent, Circle* circleArr) {
	// �湮�ߴٸ� ����
	if (visitArr[node]) return;

	visitArr[node] = true;
	if (circleArr[parent].isInside(circleArr[node])) {
		parenting(parentArr, node, parent);
		dfs(parentArr, visitArr, parentArr[node], node, circleArr);
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
			
			int size = circleInput + 1;
			bool* visitArr = new bool[size];
			for (int i = 0; i < circleInput; i++)
				visitArr[i] = false;
			visitArr[circleInput] = true;
			// �Է¹��� ���� 0 ���� �Է¹ޱ� �ٷ� �� ���� ���ʷ� ���Ͽ� ���ԵǴ��� Ȯ���Ѵ�.
			for (int i = 0; i < circleInput; i++) {
				// ������ �ȴٸ� ���ϴ� ���� �θ� �Է¹��� ������ �����Ѵ�.
				// i��° ���� �θ� �Է¹��� ������ �ٲ۴�.
				dfs(parentArr, visitArr, i, circleInput, circleArr);
			}
			delete[] visitArr;
		}

		bool* ret = new bool[N];
		for (int i = 0; i < N; i++) {
			ret[i] = false;
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (ret[parentArr[i]] == false) {
				ret[parentArr[i]] = true;
				ans++;
			}		
		}
		cout << ans << endl;
		delete[] ret;
		delete[] parentArr;
		delete[] circleArr;
	}
	return 0;
}