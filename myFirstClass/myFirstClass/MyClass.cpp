#include <iostream>
using namespace std;
class Point {
	int x, y;
public:
	int getX();
	int getY();
	void setXY(int nX, int nY); //涝仿
	Point();		//积己磊
	Point(int nX, int nY);
	~Point();		//家戈磊
};
int Point::getX(){
	return x;
}
int Point::getY() {
	return y;
}
Point::Point() {
	printf("唱积己凳\n");
}
Point::Point(int nX, int nY) {
	x = nX;
	y = nY;
}
Point::~Point() {
	printf("唱家戈凳\n");
}
int main() {
	Point p1;
	Point p2(2, 5);
	cout << "X=" << p2.getX()<<endl;
	return 0;
}

