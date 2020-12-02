//STL : Standrad Template Library
//알고리즘, 컨테이너, 반복자 등

#include <iostream>
#include <queue>
using namespace std;

void printQ(queue<int>q);

int main() {
	queue<int> myQ;
	myQ.push(10);
	myQ.push(20);
	myQ.push(50);
	cout << "Q size     : " << myQ.size() << endl;
	cout << "front Data : " << myQ.front() << endl; 
	
	for (auto i = myQ.front(); i != myQ.back(); i++) {
		cout << i << " ";
	}

	cout << "\n";
	myQ.pop();
	for (auto i = myQ.front(); i != myQ.back(); i++) {
		cout << i << " ";
	}

	printQ(myQ);


	return 0;
}

void printQ(queue<int>q) {
	cout << "\n--큐 내용 보여주기--\n";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n";
}
