// enums.cpp

// A complete C++ Program
#include <iostream>

enum class Color: unsigned int {
     Red = 0xFF0000,
     Green = 0x008000,
     Yellow = 0xFFFF00,
     Purple = 0x800080,
     Blue = 0x0000FF,
     Black = 0x000000,
     White = 0xFFFFFF
};

void print_rgb(Color);

int main(int argc, char** argv)
{
    Color colors[] = {Color::Yellow, Color::Purple, Color::Green};
    for (Color color: colors) {
        print_rgb(color);
    }

    return 0;
}

void print_rgb(Color color) {
   unsigned int value = static_cast<unsigned int>(color);

    unsigned int red = (value >> 16) & 0xFF;
    unsigned int green = (value >> 8) & 0xFF;
    unsigned int blue = value & 0xFF;

    std::cout << "RGB(" << red << ", " << green << ", "
              << blue<<")" << std::endl;
}
