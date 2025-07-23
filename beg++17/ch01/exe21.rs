#![allow(dead_code, unused)]

use std::io::{self, Write};

fn main() {
    let mut radius = 0.0;
    if let Some(input) = cin("Enter a radius: ") {
        radius = input.trim().parse::<f64>().unwrap();
    }

    println!("{:.3}", std::f64::consts::PI * f64::powf(radius, 2.0));
}

fn cin(msg: &str) -> Option<String> {
    print!("{} ", msg);
    io::stdout().flush();
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("can't read line");
    Some(line.to_string())
}
