#![allow(dead_code, unused)]

use cin::cin;

fn main() {
    let number = cin!["Enter a number: ", u32];
    let inverted_numbers = !number;
    println!(
        "| {:>8} | {:>8} | {:>8} |",
        "Original", "Inverted", "Others"
    );

    println!(
        "| {:>#08X} | {:>#08X} | {:<#08X} |",
        number,
        inverted_numbers,
        inverted_numbers + 1
    );

    println!(
        "| {:>8} | {:>8} | {:>8} |",
        number,
        inverted_numbers,
        (inverted_numbers + 1)
    );
}
