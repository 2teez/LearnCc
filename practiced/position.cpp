// position.cpp

// A complete C++ Program
#include <iostream>
#include <cmath>

struct Point
{
  public:
    explicit Point(float cx = 0, float cy = 0): x(cx), y(cy) {}
    virtual float distance() const = 0;
    virtual ~Point() = default;
  protected:
    float x;
    float y;
};

class Position: public Point {
    public:
        explicit Position(float cx = 0, float cy = 0): Point(cx, cy){}
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
    return 0;
}
