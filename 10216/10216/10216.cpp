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

// A의 부모를 B로 바꾼다.
void parenting(int* arr, int nodeA, int nodeB) {
	int parentA = find(arr, nodeA);
	int parentB = find(arr, nodeB);

	arr[parentA] = parentB;
}

void dfs(int* parentArr, bool* visitArr, int node, int parent, Circle* circleArr) {
	// 방문했다면 리턴
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
		// 각 원들의 부모들을 초기화 시킨다. 각각 자기 자신을 가르키도록 한다.
		for (int parentInit = 0; parentInit < N; parentInit++) {
			parentArr[parentInit] = parentInit;
		}
		// 원을 하나씩 입력받는다.
		for (int circleInput = 0; circleInput < N; circleInput++) {
			int x, y, R;
			cin >> x >> y >> R;
			circleArr[circleInput] = Circle(x, y, R);
			
			int size = circleInput + 1;
			bool* visitArr = new bool[size];
			for (int i = 0; i < circleInput; i++)
				visitArr[i] = false;
			visitArr[circleInput] = true;
			// 입력받은 원과 0 부터 입력받기 바로 전 원을 차례로 비교하여 포함되는지 확인한다.
			for (int i = 0; i < circleInput; i++) {
				// 포함이 된다면 비교하는 원의 부모를 입력받은 원으로 설정한다.
				// i번째 원의 부모를 입력받은 원으로 바꾼다.
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