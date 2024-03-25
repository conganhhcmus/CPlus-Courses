#pragma once

class Point2D {
private:
	int _x;
	int _y;
public:
	int getX();
	int getY();
	void setX(int value);
	void setY(int value);
public:
	Point2D();
public:
	void input();
	void output();
};