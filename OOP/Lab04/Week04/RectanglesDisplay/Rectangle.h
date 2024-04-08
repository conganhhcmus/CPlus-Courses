#pragma once
#include <string>  
#include <iostream> 
#include <sstream>  

using namespace std;
class Rectangle {
private:
    int _width;
    int _height;
public:
    Rectangle();
    Rectangle(int width, int height);
    ~Rectangle();
    int getWidth();
    int getHeight();
    string toString();
};