#![allow(dead_code, unused)]

use cin::cin;

fn main() {
    let mut arr = Vec::<f64>::new();
    let size = cin!["Enter array size: ", u64];

    for value in 0..size {
        arr.push(1.0 / f64::powf((value as f64) + 1.0, 2.0));
    }

    println!("{}", f64::sqrt(arr.iter().sum::<f64>() * 6.0));
}
