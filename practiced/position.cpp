// position.cpp

// A complete C++ Program
#include <iostream>
#include <cmath>
#include <memory>

struct Point
{
  public:
    explicit Point(float cx = 0, float cy = 0): x(cx), y(cy) {}
    Point(const Point& pt): x(pt.x), y(pt.y) {}
    Point& operator=(const Point& pt)
    {
        if (this != &pt)
        {
            x = pt.x;
            y = pt.y;
        }
        return *this;
    }
    virtual float distance() const = 0;
    virtual ~Point() = default;
  protected:
    float x;
    float y;
};

class Position: public Point {
    public:
        explicit Position(float cx = 0, float cy = 0): Point(cx, cy){}
        explicit Position(const Point& pt): Point(pt) {}
        float distance() const override
        {
            return std::sqrt(std::pow(x, 2.0) + std::pow(y, 2.0));
        }
        ~Position() = default;
};

int main(int argc, char** argv)
{

    Position pt(1.35f, 0.125f);
    std::cout << "Calculated distance: " << pt.distance() << "\n";
    //
    auto pt2 = std::make_unique<Position>(Position(3.1, 0.67));
    std::cout << pt2->distance() << "\n";

    return 0;
}
