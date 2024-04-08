#include "iostream"
#include "RectangleProvider.h"
#include "SolidRectangleConverter.h"
#include "HollowRectangleConverter.h"

using namespace std;

int main()
{
    auto rectangles = RectangleProvider::getAll();
    SolidRectangleConverter solid("*");
    HollowRectangleConverter hollow("-");

    for (auto rectangle : rectangles) {
        cout << rectangle.toString() << "\n";
        cout << solid.convert(rectangle) << "\n";
        cout << hollow.convert(rectangle) << "\n";
        cout << "\n";
    }
}