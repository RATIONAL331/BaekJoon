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
		return (posX - c.posX) * (posX - c.posX) + (posY - c.posY) * (posY - c.posY) <= radius * radius + c.radius * c.radius;
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
int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		Circle* circleArr = new Circle[N];
		int* parentArr = new int[N];
		for (int parentInit = 0; parentInit < N; parentInit++) {
			parentArr[parentInit] = parentInit;
		}
		for (int circleInput = 0; circleInput < N; circleInput++) {
			int x, y, R;
			cin >> x >> y >> R;
			circleArr[circleInput] = Circle(x, y, R);
		}
		delete[] parentArr;
		delete[] circleArr;
	}
	return 0;
}