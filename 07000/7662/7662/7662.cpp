#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct DualPriorityQueue {
    multiset<int> s;

    int size() {
        return s.size();
    }

    bool isEmpty() {
        return (s.size() == 0);
    }

    void insert(int x) {
        s.insert(x);
    }
 
    int getMin() {
        return *(s.begin());
    }
 
    int getMax() {
        return *(s.rbegin());
    }
   
    void deleteMin() {
        if (s.size() == 0)
            return;
        s.erase(s.begin());
    }
  
    void deleteMax() {
        if (s.size() == 0)
            return;
        s.erase(--s.end());
    }
};

int main() {
	int T;
	cin >> T;

	int k;
	char op;
	int num;
	while (T--) {	
        DualPriorityQueue dpq;
		cin >> k;
		while (k--) {
			cin >> op >> num;
			if (op == 'I') dpq.insert(num);
			else {
				if (num == 1) dpq.deleteMax();
				else dpq.deleteMin();
			}
		}
        if (dpq.isEmpty()) cout << "EMPTY" << '\n';
        else cout << dpq.getMax() << " " << dpq.getMin() << '\n';
	}
	return 0;
}