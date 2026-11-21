#![allow(dead_code, unused)]

#[derive(Debug)]
enum Color {
    Red = 0xFF0000,
    Green = 0x008000,
    Yellow = 0xFFFF00,
    Purple = 0x800080,
    Blue = 0x0000FF,
    Black = 0x000000,
    White = 0xFFFFFF,
}

fn main() {
    let red = Color::Red;
    print_rgb(red);
    let green = Color::Green;
    print_rgb(green);
}

fn print_rgb(color: Color) {
    let value: u32 = color as u32;

    let red = (value >> 16) & 0xFF;
    let green = (value >> 8) & 0xFF;
    let blue = value & 0xFF;

    println!("RGB({}, {}, {})", red, green, blue);
}
