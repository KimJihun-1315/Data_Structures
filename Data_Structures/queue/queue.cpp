//STL : Standrad Template Library
//�˰���, �����̳�, �ݺ��� ��

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
	cout << "\n--ť ���� �����ֱ�--\n";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n";
}
