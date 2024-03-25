#pragma once

class Line {
private:
	int _x1;
	int _x2;
	int _y1;
	int _y2;
public:
	int getX1();
	int getX2();
	int getY1();
	int getY2();
	void setX1(int value);
	void setX2(int value);
	void setY1(int value);
	void setY2(int value);
public:
	Line();
public:
	void input();
	void output();
};