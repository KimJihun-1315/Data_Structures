#include <iostream>
using namespace std;
class Point {
	int x, y;
public:
	int getX();
	int getY();
	void setXY(int nX, int nY); //�Է�
	Point();		//������
	Point(int nX, int nY);
	~Point();		//�Ҹ���
};
int Point::getX(){
	return x;
}
int Point::getY() {
	return y;
}
Point::Point() {
	printf("��������\n");
}
Point::Point(int nX, int nY) {
	x = nX;
	y = nY;
}
Point::~Point() {
	printf("���Ҹ��\n");
}
int main() {
	Point p1;
	Point p2(2, 5);
	cout << "X=" << p2.getX()<<endl;
	return 0;
}

