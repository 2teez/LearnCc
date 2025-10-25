// virtual_function.cpp

// A complete C++ Program
#include <cstring>
#include <iostream>
#include <cmath>

#define PI ((22.0)/(7.0))

class TwoDShape {
    double width, height;
    protected:
    char name[20];
    public:
    TwoDShape(): width(0), height(0) {
        std::strcpy(name, "generic");
    }
    TwoDShape(
        const char* nname,
        double variable
    ): width(variable), height(variable) {
        std::strcpy(name, nname);
    }
    TwoDShape(
        const char* nname, double h,
        double w
    ): width(w), height(h) {
        std::strcpy(name, nname);
    }
    double get_height() const { return height; }
    double get_width() const { return width; }
    void set_height(double height) { this->height = height; }
    void set_width(double width) { this->width = width; }
    virtual double area() const = 0;
    virtual void show_shape() const { std::cout << name << "\n"; }
    virtual ~TwoDShape() = default;
};

class Circle: public TwoDShape {
    double radius;
    public:
    Circle(): radius(0) {
        std::strncpy(name, "Circle", strlen(name));
    }
    Circle(double radius): TwoDShape("Circle", radius), radius(radius) {}
    double area() const override { return PI * pow(radius, 2.0);}
    void show_shape() const override { std::cout << name << " Area is : " << area() << "\n"; }
    ~Circle() = default;
};

int main(int argc, char** argv)
{

    Circle c(3.25), *cc;
    TwoDShape* p = &c;
    cc = &c;
    p->show_shape();
    cc->show_shape();

    return 0;
}
