#![deny(clippy::all, clippy::pedantic, unused)]

use std::ops::Add;

fn main() {
    println!("{}", add(4, 8));
    let a = 3.09;
    let b = 0.135;
    println!("{:.3}", add(a, b));
}

fn add<T: Add<Output = T>>(a: T, b: T) -> T {
    a + b
}
